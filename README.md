# VitalSync remote health monitoring

## Description
This project aims to develop an IoT health monitoring system using the MAX30102 sensor, an integrated SpO2 (blood oxygen saturation) and BPM (heart rate) sensor. The sensor will retrieve vital signs data from the patient and upload it to a Realtime Database in Firebase. The system is built around the ESP32 microcontroller, which handles the data acquisition from the sensor and the communication with the Firebase database.

## Components
- MAX30102 Sensor (DFRobot)
- ESP32 Microcontroller
- Firebase Realtime Database

## Project Structure
  - **vitalsync_V1.ino:** This file contains the main code for the project.
  - **README.md:** This file provides an overview of the project and instructions for setup and usage.

## Setup Instructions
1. **Hardware Setup:**
   - Connect the MAX30102 sensor to the ESP32 microcontroller as per the manufacturer's instructions.
   - https://wiki.dfrobot.com/Heart_Rate_and_Oximeter_Sensor_V2_SKU_SEN0344
   - Ensure proper power supply and connections.

2. **Software Setup:**
   - Install the Arduino IDE (if not already installed).
   - Install the necessary ESP32 board support in the Arduino IDE.
   - Install the Firebase Arduino library.

3. **Firebase Configuration:**
   - Create a Firebase project and set up a Realtime Database.
   - Obtain the Firebase project credentials (database URL, authentication key).

4. **Code Configuration:**
   - Open the `vitalsync_V1.ino` file in the Arduino IDE.
   - Replace the placeholder Firebase credentials with your actual credentials.
   - Adjust any other configuration parameters as needed.

5. **Upload Code:**
   - Compile and upload the code to the ESP32 microcontroller.

## Usage
1. Power on the ESP-32.
2. The ESP32 will initialize and start reading data from the MAX30102 sensor.
3. The sensor data (SpO2 and BPM) will be logged into the Firebase Realtime Database.
4. Access the Firebase Realtime Database to view the live patient vital signs data.

## Notes
- Ensure proper sensor placement for accurate readings.
- Movements may cause inaccurate readings.

## Contributors
- [Advaith Maonj/Vitalsync]
