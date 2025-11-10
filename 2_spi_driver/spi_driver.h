#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <stdint.h>

// SPI configuration structure
typedef struct {
    uint8_t mode;        // SPI mode (0-3)
    uint32_t clk_speed;  // clock speed in Hz
    uint8_t bit_order;   // MSB or LSB first
} spi_config_t;

// SPI modes
#define SPI_MODE_0  0
#define SPI_MODE_1  1
#define SPI_MODE_2  2
#define SPI_MODE_3  3

#define SPI_MSB_FIRST  0
#define SPI_LSB_FIRST  1


// Function prototypes
int spi_init(spi_config_t *cfg);
void spi_deinit(void);
uint8_t spi_transfer(uint8_t data);
int spi_transfer_buffer(uint8_t *tx_buf, uint8_t *rx_buf, uint16_t len);
void spi_write(uint8_t *data, uint16_t len);
void spi_read(uint8_t *buf, uint16_t len);

#endif
