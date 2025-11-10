#include "spi_driver.h"
#include <stdio.h>

// Hardware register addresses (example for generic MCU)
#define SPI_CR1     (*((volatile uint32_t*)0x40013000))
#define SPI_CR2     (*((volatile uint32_t*)0x40013004))
#define SPI_SR      (*((volatile uint32_t*)0x40013008))
#define SPI_DR      (*((volatile uint32_t*)0x4001300C))

// Control register bits
#define SPI_CR1_SPE     (1 << 6)   // SPI enable
#define SPI_CR1_MSTR    (1 << 2)   // Master mode
#define SPI_SR_TXE      (1 << 1)   // TX buffer empty
#define SPI_SR_RXNE     (1 << 0)   // RX buffer not empty


static spi_config_t current_cfg;

/**
 * Initialize SPI peripheral with given configuration
 */
int spi_init(spi_config_t *cfg) {
    if(cfg == NULL) {
        return -1;
    }
    
    // Store config
    current_cfg = *cfg;
    
    // Disable SPI first
    SPI_CR1 &= ~SPI_CR1_SPE;
    
    // Configure mode
    uint32_t cr1_val = 0;
    cr1_val |= SPI_CR1_MSTR;  // master mode
    
    // Set clock polarity and phase based on mode
    switch(cfg->mode) {
        case SPI_MODE_0:
            // CPOL=0, CPHA=0
            break;
        case SPI_MODE_1:
            cr1_val |= (1<<0);  // CPHA=1
            break;
        case SPI_MODE_2:
            cr1_val |= (1<<1);  // CPOL=1
            break;
        case SPI_MODE_3:
            cr1_val |= (1<<1) | (1<<0);
            break;
    }
    
    // FIXME: calculate proper baud rate prescaler from clk_speed
    cr1_val |= (3 << 3);  // BR[2:0] = 011 (fPCLK/16)
    
    SPI_CR1 = cr1_val;
    
    // Enable SPI
    SPI_CR1 |= SPI_CR1_SPE;
    
    return 0;
}

void spi_deinit(void) {
    SPI_CR1 &= ~SPI_CR1_SPE;
}

/**
 * Transfer single byte over SPI
 * Sends data and returns received byte
 */
uint8_t spi_transfer(uint8_t data) {
    // Wait until TX buffer is empty
    while(!(SPI_SR & SPI_SR_TXE));
    
    // Write data to DR
    SPI_DR = data;
    
    // Wait until RX buffer has data
    while(!(SPI_SR & SPI_SR_RXNE));
    
    // Read and return received data
    return (uint8_t)SPI_DR;
}

// Multi-byte transfer function
int spi_transfer_buffer(uint8_t *tx_buf, uint8_t *rx_buf, uint16_t len) {
    if(len == 0) return -1;
    
    uint16_t i;
    for(i=0; i<len; i++) {
        uint8_t tx_data = (tx_buf != NULL) ? tx_buf[i] : 0xFF;
        uint8_t rx_data = spi_transfer(tx_data);
        
        if(rx_buf != NULL) {
            rx_buf[i] = rx_data;
        }
    }
    
    return 0;
}

// Send only (no receive)
void spi_write(uint8_t *data, uint16_t len) {
    uint16_t i;
    for(i=0; i<len; i++) {
        spi_transfer(data[i]);
    }
}

// Receive only (send dummy bytes)
void spi_read(uint8_t *buf, uint16_t len) {
    uint16_t i;
    for(i=0; i<len; i++) {
        buf[i] = spi_transfer(0xFF);
    }
}

// TODO: add DMA support for faster transfers
