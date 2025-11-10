# SPI Driver

A simple SPI (Serial Peripheral Interface) driver for embedded systems. This driver provides basic functionality to communicate with SPI devices in master mode. It's designed to be straightforward and easy to integrate into your embedded projects.

## What It Does

The driver handles SPI communication with support for all four SPI modes (0-3). You can initialize the SPI peripheral with your desired clock polarity and phase settings, then use the transfer functions to send and receive data. It supports single-byte transfers as well as multi-byte buffer operations.

The implementation uses memory-mapped registers to directly control the SPI hardware. I've included functions for write-only and read-only operations too, which is handy when you're working with devices that only need data in one direction.

## Features

- Supports all SPI modes (0-3) with configurable clock polarity and phase
- Master mode operation
- Single byte transfer with simultaneous send/receive
- Multi-byte buffer transfers
- Separate write-only and read-only functions
- Simple initialization and configuration

## Usage

First, set up your SPI configuration:

```c
spi_config_t spi_cfg = {
    .mode = SPI_MODE_0,
    .clk_speed = 1000000,  // 1 MHz
    .bit_order = SPI_MSB_FIRST
};

spi_init(&spi_cfg);
```

Then you can transfer data:

```c
// Single byte transfer
uint8_t received = spi_transfer(0xAA);

// Write multiple bytes
uint8_t tx_data[] = {0x01, 0x02, 0x03};
spi_write(tx_data, 3);

// Read multiple bytes
uint8_t rx_buffer[10];
spi_read(rx_buffer, 10);

// Full duplex transfer
uint8_t tx_buf[] = {0x10, 0x20, 0x30};
uint8_t rx_buf[3];
spi_transfer_buffer(tx_buf, rx_buf, 3);
```

## Compilation

Just include the source files in your project:

```bash
gcc -c spi_driver.c -o spi_driver.o
```

Or add them to your embedded toolchain build system. Make sure to adjust the register addresses in the code to match your specific microcontroller.

## Notes

The hardware register addresses are currently set for a generic example. You'll need to update them based on your MCU's datasheet. The baud rate prescaler calculation is also simplified - you might want to make it more precise for your application.

## Status
- [x] Basic structure and header file
- [x] Initialization function
- [x] Data transfer functions
- [x] Multi-byte operations
- [ ] DMA support (future enhancement)
