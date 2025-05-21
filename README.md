# IoT-Based Heart Health Monitoring and Prediction System

An end-to-end IoT system using ESP8266, MAX30100 pulse oximeter, DHT11 sensor, ThingSpeak, Blynk, and deep learning models for **real-time monitoring**, **predictive analysis**, and **anomaly detection** of heart rate and temperature.

## Features

-  Sends real-time heart rate, SpO₂, and temperature data to ThingSpeak
-  Uses a trained **ConvLSTM model** to predict heart rate for the next 60 seconds
-  Supports anomaly detection using a separate ML model
-  Visualizes live and predicted heart rate data on **Blynk mobile app**
-  Sends notifications to Blynk in case of abnormal heart rate patterns

---

##  Technologies Used

| Component | Description |
|----------|-------------|
| **ESP8266** | Microcontroller for data acquisition and WiFi communication |
| **MAX30100** | Heart rate and SpO₂ sensor |
| **DHT11** | Temperature sensor |
| **ThingSpeak** | IoT cloud platform for storing and retrieving data |
| **Blynk** | Mobile app for IoT visualization and alerts |
| **TensorFlow / Keras** | Used for predictive model and anomaly detection |
| **Python** | For backend data fetching, prediction, and communication |

---

## Hardware Requirements

- ESP8266 NodeMCU
- MAX30100 Pulse Oximeter Sensor
- DHT11 Temperature Sensor
- Jumper Wires and Breadboard
- Micro USB Cable
- Internet Wi-Fi Connection

---

## 🔧 Setup Instructions

### 🖥️ ESP8266 (Arduino IDE)

1. **Install Required Libraries**:
   - `ESP8266WiFi`
   - `ThingSpeak`
   - `DHT`
   - `MAX30100_PulseOximeter`

2. **Upload the `ESP8266.ino` Code**:
   - Replace WiFi SSID and Password
   - Replace your ThingSpeak Channel ID and API Key
---

### 🧠 Python Backend (AI Prediction + Blynk)

1. **Install Dependencies**:
   ```bash
   pip install tensorflow numpy requests
**Prepare Models:**
CONVLSTM_30EPOCHS.h5 – ConvLSTM heart rate predictor
ANOMALY_DETECTION.h5 – Binary anomaly detection model

2. **Run the Python Script:**
Make sure to update your ThingSpeak and Blynk credentials in the script.

3. **ThingSpeak Channel Fields**
Field	Data
1	Heart Rate (BPM)
2	SpO₂ (%)
3	Temperature (°C)

4. **Blynk Integration**

V0 – Live heart rate
V2 – Predicted average heart rate
Notifications – Sent via Blynk cloud if anomaly detected

5. **Model Info**
ConvLSTM Model: Predicts heart rate for the next 60 seconds using last 140 data points.
Anomaly Detection Model: Binary classifier to flag abnormal patterns in predicted HR.

---

## Sample Output

📡 Sending to ThingSpeak:
💓 BPM: 78.1
🩸 SpO2: 98.2
🌡️ Temp: 36.5
✅ Data sent to ThingSpeak!

Got past 60 heart rate values from ThingSpeak
Past HR values: [77.5 78.2 79.1 78.7 77.9] ...
Predicted next HR (next 60 sec): [78.6 78.5 78.4 ...]
Predicted Avg HR: 78.45

---

## Future Improvements
Add SpO₂ prediction using time-series modeling
Enable real-time dashboard using Dash or Flask
Integrate cloud database like Firebase or MongoDB
Enhance model accuracy with more data and epochs

---

## License
This project is open-source and free to use under the MIT License.

---

## Acknowledgements
ThingSpeak API by MathWorks
Blynk IoT Platform
TensorFlow for Deep Learning
---
