# Senior Project

Work done for senior project at UOP.
Project goal was to create an autonomous golf cart to serve as a sort of taxi for students.
This goal proved far too lofty, so we shifted gears and successfully implemented a brake assist system for the cart.
My contributions are as follows:
 - **[mcu/](./mcu):** Code for a TM4C LaunchPad microcontroller board, to communicate as a USB device between cart computer and peripherals.
Contains module to receive & parse NMEA sentences from Adafruit GPS chip and module to control H-Bridge braking circuit.
 - **[geotracking/](geotracking/):** Python script to track the cart's position on campus, determine a path from pickup to destination, and track progress along that path.
Receives coordinates from GPS module via a microcontroller.
 - **[BTAdmin](btadmin/):** Administrative Python script that, with processed data from the onboard sensors, decides when to pull the brakes and stop the vehicle.
Uses UDS sockets to receive input from the sensors and send commands to the brake controls.

The full report for our project can be found [here]().