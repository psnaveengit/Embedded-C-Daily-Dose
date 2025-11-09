# SPI Driver

Started working on a basic SPI driver for embedded systems. This is gonna be pretty simple - just the core functionality to get SPI communication working.

Right now I've got the initialization part done with mode configuration (SPI modes 0-3). The driver can set up the SPI peripheral as a master device with different clock polarities and phases.

Still need to add the actual data transfer functions and maybe some error handling. Work in progress!

## Status
- [x] Basic structure and header file
- [x] Initialization function
- [ ] Data transfer functions
- [ ] Error handling
