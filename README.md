# Autonomous Beverage Machine

This repository contains the source code and documentation for the Autonomous Beverage Machine, a university project designed to automate the process of serving mixed drinks. With some modifications, this machine could be implemented in bars or nightclubs. The project combines hardware and software to deliver a seamless, fully automated experience.

---

## Features

- **RFID Reader**: Identifies users through associated cards.
- **Infrared Sensor**: Detects the presence of a glass.
- **Load Cell (Scale)**: Measures the amount of liquid dispensed.
- **Relays and Pumps**: Four relays control four pumps to dispense different liquids.
- **LCD Display**: Provides real-time feedback during operation.
- **WiFi Connectivity**: Uses an ESP32 as a bridge for the main microcontroller (LPC845).

---

## Software Overview

### Graphical User Interface (GUI)
- **Framework**: Built with Qt.
- **Purpose**: Allows users to log in using a username and password, place drink orders, and manage account information.
- **Database Integration**: Connected to a MySQL database with two tables:
  - Users
  - Drink Orders (one-to-many relationship with Users)

### Backend Communication
- **API**: The hardware communicates with the database via an HTTP API.
  - **Functions**: Handles order requests and deletions.

### Programming Languages
- **C/C++**: Used for programming the microcontrollers and implementing communication protocols.
- **AT Commands**: Used for serial communication between devices.

---

## How It Works

1. **User Registration**:
   - Users are registered in the database with an RFID card.
2. **Placing an Order**:
   - Users log in through the GUI and select their desired drink combination.
   - Orders are stored in the database.
3. **Dispensing a Drink**:
   - Users tap their RFID card on the machine.
   - The machine retrieves the associated order via the API.
   - The drink is dispensed according to the order:
     - The scale measures the liquid level.
     - The system switches pumps to serve multiple liquids as required.
4. **Real-Time Feedback**:
   - The LCD displays the status of the operation.

---

## Hardware Components

- **Microcontrollers**: ESP32 (WiFi bridge) and LPC845 (main controller).
- **Modules**:
  1. RFID Reader
  2. Infrared Sensor
  3. Load Cell Module
  4. Four Relays
  5. Four Pumps
  6. LCD Display
  7. WiFi Module

---

## Challenges and Learnings

- **Networking**: Gained hands-on experience with HTTP protocols and database integration.
- **Hardware Integration**: Learned to work with multiple hardware modules and ensure seamless communication.
- **Team Coordination**: Developed skills in project management and effective collaboration.



