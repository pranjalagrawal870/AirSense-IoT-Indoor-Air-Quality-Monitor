# AirSense-IoT-Indoor-Air-Quality-Monitor
An IoT-based system that monitors indoor air quality in real-time using an ESP8266 microcontroller and gas sensor, with cloud integration via ThingSpeak.
📸 Project Overview

AirSense IoT continuously measures indoor air pollution levels and:

Displays real-time data on an LCD
Alerts users via buzzer when air quality is poor
Sends data to cloud for remote monitoring
⚙️ Features

✅ Real-time air quality monitoring
✅ LCD display (16x2 I2C)
✅ Buzzer alert system
✅ WiFi connectivity (ESP8266)
✅ Cloud data logging (ThingSpeak)
✅ Low-cost and easy to build

🧠 How It Works
Gas sensor detects air pollutants
ESP8266 reads analog values
Data displayed on LCD
If threshold exceeds → buzzer alert
Data sent to ThingSpeak every 15 seconds
🧰 Components Used
ESP8266 (NodeMCU)
MQ-135 Gas Sensor
16x2 I2C LCD Display
Buzzer
Breadboard & Jumper Wires
