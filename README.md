

# ✨ Weather Monitoring System

This project monitors **temperature & humidity** using a **DHT22 sensor** and displays the data on an **LCD screen**. If the temperature exceeds **30°C**, an **LED blinks 5 times** as a warning.

## 🛠️ Components & Connections

| **Component**   | **Arduino Pin**            |
|---------------|--------------------------|
| **LCD (I2C)**   | SDA → A4, SCL → A5  |
| **DHT22**       | Data → A2, VCC → 5V, GND → GND |
| **LED**         | Anode → D8 (via 220Ω resistor), Cathode → GND |

## 🎯 Working Principle
1. **DHT22 sensor** measures **temperature & humidity**.
2. Data is displayed on **LCD**.
3. If **temperature > 30°C**, the **LED blinks 5 times**.
4. Updates every **2 seconds**.

## 🔍 Features & Future Enhancements
✔️ Real-time temperature & humidity monitoring  
✔️ Automatic LED warning for high temperatures  
✔️ Efficient I2C LCD communication  

**Enhancements:**  
- Add a **buzzer** for alerts  
- Store data in an **SD card**  
- Send alerts via **WiFi/Bluetooth**  

## 🌐 Summary
A simple **Arduino-based system** to monitor temperature & humidity with a visual warning system for high temperatures. Great for **learning sensor interfacing & LCD communication!** 🚀

