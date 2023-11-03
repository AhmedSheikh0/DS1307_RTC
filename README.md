#Atmega32 Communicating with RTC (DS1307) using I2C
This repository provides an example code and wiring instructions for communicating between an Atmega32 microcontroller and the DS1307 Real-Time Clock (RTC) module using the I2C protocol. The Atmega32 is used as the master device, while the DS1307 acts as the slave device.

##Prerequisites
Before proceeding, make sure you have the following:
  - ATmega32 microcontroller board
  - DS1307 RTC module
  - Appropriate cables and connectors
  - AVR-GCC compiler
  - AVRDUDE programmer

##Wiring Instructions
Follow these steps to connect the Atmega32 and DS1307 modules:

  - Connect the SDA (Serial Data Line) pin of the DS1307 module to the SDA pin (Pin 27) of the Atmega32.
  - Connect the SCL (Serial Clock Line) pin of the DS1307 module to the SCL pin (Pin 28) of the Atmega32.
  - Connect the VCC (Power) pin of the DS1307 module to the 5V pin of the Atmega32.
  - Connect the GND (Ground) pin of the DS1307 module to the GND pin of the Atmega32.
  - Make sure to double-check the pin connections and ensure that the power supply voltages match the requirements of both devices.

##Code Usage
Clone or download this repository to your local machine.
Open the project in your preferred AVR-GCC development environment (e.g., Atmel Studio or AVR-GCC command line tools).
Locate the main.c file, which contains the example code for communicating with the DS1307 RTC module.
Modify the code as needed to suit your requirements. The provided code demonstrates basic functionalities such as reading and writing time and date values.
Compile the code using the AVR-GCC compiler.
Program the Atmega32 microcontroller using AVRDUDE or any other suitable programmer.
Run the code on the Atmega32 and observe the output.

##Additional Notes
   - The example code assumes that the necessary I2C libraries are available and configured for the Atmega32 microcontroller. Make sure to include the appropriate libraries in your project.
  - Refer to the datasheet of the DS1307 RTC module for more information about its functionality and register addresses.
  - Ensure that the I2C bus operates at the correct clock frequency. Adjust the clock frequency settings in the code if needed.
  - Take proper precautions while handling electrical components and connections. Double-check the wiring and power supply connections before applying power.

##Contributing
Contributions to this repository are welcome! If you encounter any issues, have suggestions, or want to add improvements, please feel free to submit a pull request.

##License
This project is licensed under the MIT License.

##Acknowledgments
The code in this repository was inspired by various online resources and tutorials. Thank you to all the contributors of those resources.
