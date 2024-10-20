# IoT-Based Paralysis Patient Healthcare System

## Overview
The **IoT-Based Paralysis Patient Healthcare System** is an innovative healthcare solution designed to assist caregivers in monitoring the vital signs of paralysis patients in real-time. This system integrates various sensors to measure critical health parameters such as body temperature and heart rate. It uses a GSM module to send emergency alerts via SMS when abnormal conditions are detected. The system is powered by an Arduino microcontroller, ensuring a reliable, low-cost solution for continuous patient monitoring.

## Key Features
- **Real-time Monitoring**: Constant monitoring of critical health parameters (body temperature and heart rate) for early detection of medical emergencies.
- **Emergency Alert System**: Sends an automated SMS alert to caregivers when abnormal vital signs are detected.
- **Buzzer Alarm**: Triggers a buzzer alarm in the event of an emergency for immediate local response.
- **Low-Cost and Scalable**: Built using affordable hardware (Arduino, sensors, GSM module) with the potential for expansion by integrating additional sensors.

## Hardware Components
- **Arduino UNO**: The microcontroller used for controlling all components.
- **LM35 Temperature Sensor**: For continuous body temperature monitoring.
- **Heart Rate Sensor**: For monitoring heart rate (BPM).
- **GSM Module (SIM900/800)**: Used to send SMS alerts during emergencies.
- **Buzzer**: For audible alerts in critical conditions.
- **Breadboard and Jumper Wires**: For connecting components.

## Software Components
- **Arduino IDE**: The programming environment used to write and upload code to the Arduino.
- **SoftwareSerial Library**: For GSM module communication.
- **Embedded C/C++**: Code for reading sensor values and sending alerts.

## System Architecture
The system consists of the following modules:
1. **Sensor Module**: Measures the patient's vital signs (temperature and heart rate).
2. **Processing Unit**: Arduino processes the sensor data and checks for emergency conditions.
3. **Alert Module**: When the patient's vitals exceed defined thresholds, the GSM module sends an emergency SMS and the buzzer sounds an alarm.
4. **Notification System**: Sends real-time SMS alerts to caregivers when abnormal readings are detected.

![System Architecture]![image](https://github.com/user-attachments/assets/db558a8a-e522-43e9-b2b4-ee4d32e1b5ad)

## How It Works
1. The system continuously reads the patient’s vital signs (temperature and heart rate).
2. If the temperature exceeds 38°C or the heart rate falls outside the safe range (60-100 BPM), the system triggers an emergency protocol.
3. An SMS alert is automatically sent to the caregiver via the GSM module.
4. A local alarm (buzzer) is triggered for immediate response.

## Installation Guide
### Hardware Setup:
1. Connect the **LM35 temperature sensor** to pin `A0` of the Arduino.
2. Connect the **heart rate sensor** to pin `A1` of the Arduino.
3. Connect the **GSM module** to pins `7` (Tx) and `8` (Rx).
4. Connect the **buzzer** to pin `6` of the Arduino.
5. Power the Arduino using a USB cable or external power source.

### Software Setup:
1. Install the **Arduino IDE** from [here](https://www.arduino.cc/en/software).
2. Download or clone this repository:
   ```bash
   git clone https://github.com/your-username/IoT-Based-Paralysis-Patient-Healthcare-System.git
