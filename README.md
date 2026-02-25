# 🏠 SMART HOME AUTOMATION SYSTEM

A complete IoT-based Smart Home Automation System using **Arduino Mega 2560** and **ESP8266**. Control and monitor your home remotely via a web interface with multiple integrated subsystems for lighting, security, safety, and environmental control.

---

## 📋 Table of Contents
- [About The Project](#about-the-project)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Subsystems](#subsystems)
- [Getting Started](#getting-started)

---

## 🎯 About The Project

This project is an integrated smart home system developed as a graduation project for Control and Computer Engineering students at Sana'a University. The system combines:

- **WiFi-based manual control** via web interface
- **Automatic control** using various sensors
- **SMS notifications** for alerts (GSM module)
- **IoT-ready architecture**

---

## 🏗️ System Architecture

The system is divided into three main categories:

All subsystems are integrated with **Arduino Mega 2560** as the main controller, with **ESP8266** for WiFi connectivity and **SIM900A** for SMS alerts.

---

## 🔧 Hardware Components

| Component | Purpose |
|-----------|---------|
| Arduino Mega 2560 | Main controller |
| ESP8266 | WiFi module for web control |
| SIM900A | GSM module for SMS alerts |
| HC-SR04 | Ultrasonic distance sensor |
| DHT11 | Temperature & humidity sensor |
| MQ-6 | Gas leak detection sensor |
| YL-69 | Soil moisture sensor |
| LDR | Light detection sensor |
| Servo Motor | Door control actuator |

---

## 🧩 Subsystems

### 🛋️ Services
- **Light System** - Indoor (WiFi control), Stair (motion activated), Outdoor (LDR sensor)
- **Water System** - Automatic pump control with ultrasonic sensor
- **Condition System** - Temperature-based fan control using DHT11
- **Humidity System** - Plant soil moisture monitoring with YL-69
- **Control Devices System** - Manual appliance control via WiFi
- **Entertainment Room** - Music rhythm LED lights
- **Parking System** - Ultrasonic parking assistance with LED indicators

### 🔒 Security
- **Door System** - Servo-controlled door via WiFi commands
- **Wall System** - Laser intrusion detection with buzzer and SMS alert

### ⚠️ Safety
- **Gas Alarm System** - MQ-6 gas detection with buzzer, LED, and SMS notification

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE (latest version)
- Required libraries: DHT sensor library, SoftwareSerial

### Installation
1. Clone this repository or download ZIP
2. Open any `.ino` file in Arduino IDE
3. Select board: **Arduino Mega 2560**
4. Upload code to your board
5. Connect to WiFi Access Point: `ESP8266_AP`
6. Open browser and go to: `http://192.168.4.1`
