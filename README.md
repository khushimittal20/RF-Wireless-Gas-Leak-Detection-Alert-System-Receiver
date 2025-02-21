# RF-Based Wireless Gas Leak Detection & Alert System - Receiver

## 📋 Project Overview
This project focuses on creating a **Receiver Module** for an RF-based wireless gas leak detection and alert system. It receives alerts from the transmitter (equipped with an MQ-6 gas sensor) and takes immediate action to prevent potential hazards.

---

## 🛠 Components Required

| Component                     | Quantity | Description                                           |
|-------------------------------|----------|-------------------------------------------------------|
| Arduino Uno                   | 1        | Main controller for the receiver                      |
| RF Receiver Module (433 MHz)  | 1        | Receives wireless signals from the transmitter        |
| Buzzer                        | 1        | Emits alarm sounds during gas leaks                   |
| LED (Red)                     | 1        | Indicates danger (gas detected)                       |
| LED (Green)                   | 1        | Indicates normal/safe status                          |
| Relay Module (5V)             | 1        | Controls exhaust fan or shuts off gas supply          |
| TM1637 4-Digit Display        | 1        | Displays received gas levels                          |
| Power Supply (9V Battery)     | 1        | Powers the Arduino and connected modules              |
| Jumper Wires                  | As needed| For making connections                                |

---

## ⚡ Working Principle

1. **Signal Reception:**
   - The **RF Receiver Module (433 MHz)** listens for signals from the transmitter.
   - When dangerous gas levels are detected by the transmitter, it sends a high signal to the receiver.

2. **Alert Mechanisms:**
   - Upon receiving the alert:
     - The **Buzzer** is activated to sound an alarm.
     - The **Red LED** lights up indicating a gas leak.
     - The **Green LED** remains on during normal conditions.
     - The **TM1637 Display** shows the received gas concentration level.

3. **Safety Control:**
   - The **Relay Module** is triggered to:
     - Turn on an **Exhaust Fan**.
     - Or **shut off the gas supply** automatically.

4. **Power Supply:**
   - The entire system is powered using a **9V Battery** or an appropriate adapter.

---

## 🔗 Circuit Connections

- **RF Receiver Module:**
  - VCC → 5V (Arduino)
  - GND → GND (Arduino)
  - Data Out → RX Pin (Handled by RH_ASK Library)

- **TM1637 4-Digit Display:**
  - CLK → Digital Pin 5 (Arduino)
  - DIO → Digital Pin 6 (Arduino)
  - VCC → 5V (Arduino)
  - GND → GND (Arduino)

- **Buzzer:**
  - Positive → Digital Pin 7 (Arduino)
  - Negative → GND

- **Relay Module:**
  - VCC → 5V (Arduino)
  - GND → GND (Arduino)
  - IN → Digital Pin 8 (Arduino)

- **LEDs:**
  - **Red LED:**
    - Anode (+) → Digital Pin 4 (Arduino)
    - Cathode (–) → GND (via 220Ω resistor)
  - **Green LED:**
    - Anode (+) → Digital Pin 2 (Arduino)
    - Cathode (–) → GND (via 220Ω resistor)

---

## 💾 Arduino Code Overview

- **Libraries Used:**
  - `RH_ASK` – For RF communication
  - `SPI` – Required by RH_ASK library
  - `TM1637Display` – For 4-digit 7-segment display

- **Features:**
  - Continuously listens for RF signals.
  - Displays received gas levels on the TM1637 display.
  - Triggers buzzer, LEDs, and relay based on received gas concentration.
  - Ensures the system returns to normal once the gas level is safe.

*(Detailed code is available in the `receiver_code.ino` file)*

---

## 🚀 How to Run the Project

1. **Assemble** all components as per the circuit diagram.
2. **Upload** the Arduino code to the Uno board.
3. **Power** the system using a 9V battery or adapter.
4. **Test** the setup by sending signals from the transmitter (e.g., simulating gas leak detection).
5. **Observe** the alerts: buzzer, LEDs, display readings, and relay activation.

---

## 📖 Future Enhancements

- Integrate an **LCD Display** to show detailed system status.
- Add a **GSM Module** to send SMS alerts to homeowners or factory managers.
- Implement **Wi-Fi** (ESP8266/ESP32) for IoT-based remote monitoring.

---

## ⚠️ Safety Precautions

- Ensure all connections are secure to avoid false alarms.
- Use a **properly rated relay** for controlling high-voltage devices.
- Test the system in a controlled environment before deploying it.

---

## 💡 Conclusion

This receiver module plays a vital role in enhancing safety by providing real-time alerts and automated controls during gas leak incidents, potentially saving lives and property.

## 👥 Team Members

- Bani Gupta
- Khushi Mittal
- Nayan Tiwari
- Sarthak Sabharwal
- Rajveer Taneja
- Deepesh

---

## 📄 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

```
