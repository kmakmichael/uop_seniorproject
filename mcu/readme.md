# Microcontroller Code
For senior project at UOP, designed for a TM4C123GX LaunchPad.
Part of a Level 1 autonomous electric golf cart.
Full automation was the original goal, but we were only able to accomplish brake control.
Project in the `hemad/` directory is used to control an H-bridge, which controls the winch that pulls the brakes.
The `usb_dev_serial/` project takes input (NMEA Sentences) from an Adafruit Ultimate GPS module and forwards the latitude/longitude data over USB.

## Code stolen from:
- [TivaWare](https://www.ti.com/tool/SW-TM4C)
- [Junaidk11](https://github.com/Junaidk11/Adafruit_GPS_Module)
