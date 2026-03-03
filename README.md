# 🏢 Smart Building Management System
A modular, scalable, and safety-critical IoT architecture for modern smart buildings.

An advanced IoT-based Smart Building Automation System developed using **Arduino Mega 2560**, **ESP8266 WiFi Module**, and **GSM Communication Module**.

The system integrates multiple intelligent building subsystems into one centralized architecture that enables real-time monitoring, remote control, and emergency alert notifications.

---

## 📌 Project Overview

The Smart Building Management System improves:

- Automation
- Security
- Safety
- Energy Efficiency

The system is organized into three main categories:

---

## 🏗 Services System

- 💡 Lighting Control System
- 💧 Water Level Monitoring
- 🌡 Temperature & Humidity Monitoring
- 🎛 Electrical Devices Control
- 🎵 Entertainment Room System

---

## 🔐 Security System

- 🚪 Smart Door Monitoring
- 🧱 Wall Intrusion Detection

---

## 🚨 Safety System

- 🔥 Gas Leakage Detection
- 🚗 Smart Parking Monitoring
- 📩 GSM Emergency Alert System

---

## 🧠 System Architecture

The system consists of:

- **Arduino Mega 2560** → Main microcontroller
- **ESP8266** → WiFi communication module
- **GSM Module** → SMS alert communication
- Environmental Sensors (DHT, MQ Gas, Ultrasonic, etc.)
- Actuators (Relays, LEDs, Buzzer, LCD Display)

---

## 🔄 System Communication & Data Flow

### 🌐 IoT Communication Flow

Sensors → Arduino Mega → ESP8266 → Web Interface  
Web Commands → ESP8266 → Arduino Mega → Actuators

### 📩 GSM Emergency Flow

Gas Detection → Arduino Mega → GSM Module → SMS Alert to User

---

## 🧪 System Operation Example

### 🔥 Gas Leakage Scenario

1. MQ Gas Sensor detects abnormal gas concentration.
2. Arduino processes sensor data.
3. Buzzer is activated immediately.
4. GSM module sends SMS alert to the user.
5. System status updates on the web interface.

### 💡 Remote Light Control Scenario

1. User presses ON button from web interface.
2. ESP8266 receives HTTP request.
3. Command is sent via Serial to Arduino Mega.
4. Arduino activates the relay.
5. Light turns ON and system updates online.

---

## System Images
### 🏗 System Overview
![System Overview](images/system_overview.png)

### 🔌 Circuit Diagram
![Circuit Diagram](images/circuit_diagram.png)

### 🌐 Web Interface
![Web Interface](images/web_interface.png)

### 🌍 System Environment
![System Environment](images/system_environment.png)

---

## ⚙️ Technologies Used

- C / C++
- Arduino IDE
- ESP8266 WiFi Communication
- GSM Serial Communication
- Embedded Systems Programming

---

## 🔌 Hardware Components

- Arduino Mega 2560
- ESP8266 WiFi Module
- GSM Module
- DHT11 / DHT22
- MQ Gas Sensor
- Ultrasonic Sensor
- Relay Module
- LCD Display
- Buzzer

---

## 🚀 Key Features

- Real-time monitoring
- Remote control via WiFi
- GSM emergency alerts
- Multi-subsystem integration
- Smart parking detection

---

## 👩‍💻 Author

**Aisha Alnawar**  
Electrical Engineering – Computer & Control Systems  
Embedded Systems & IoT Developer
