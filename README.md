# 🤖 BOD_Paradox – Ultra High-Speed Autonomous Line Following Robot

**A Precision 6-Channel IR Sensor Based High-Speed Autonomous Line Following Robot with Advanced PID Control**

---

## 🧠 Project Overview
The **BOD_Paradox Line Following Robot (LFR)** is a high-speed autonomous robotic system designed to follow a predefined track with maximum accuracy and stability.  
The robot uses a **custom-built 6-channel IR sensor array** for precise line detection and an advanced **PID (Proportional–Integral–Derivative) control algorithm** for smooth navigation and stable high-speed movement.

Unlike traditional line-following robots that rely on basic movement logic, this project utilizes continuous sensor feedback and intelligent motor correction to achieve accurate tracking on straight paths, curves, and sharp turns.

The project integrates concepts from **robotics**, **embedded systems**, **control systems**, and **automation engineering**, demonstrating practical autonomous navigation used in modern industries and smart transportation systems.

---

## 🚗 Features
- 🔹 High-speed autonomous line-following system  
- 🔹 Custom 6-channel IR sensor array for accurate detection  
- 🔹 Advanced PID control for smooth and stable movement  
- 🔹 Precise turning and curve handling  
- 🔹 Real-time motor speed correction  
- 🔹 Lightweight and efficient robot chassis  
- 🔹 Educational platform for robotics and embedded systems learning  

---

## 🧩 System Components

| Component | Function |
|------------|-----------|
| Arduino Nano | Main microcontroller |
| 6-Channel IR Sensor Array | Line detection |
| L298N / L293D Motor Driver | Motor speed and direction control |
| DC Gear Motors | Robot movement |
| Lithium Battery | Power supply |
| Chassis & Wheels | Robot structure and mobility |
| Castor Wheel | Balance and support |

---

## ⚙️ Working Principle
- The 6-channel IR sensor array continuously detects the position of the black line on the track.  
- Sensor data is sent to the Arduino Nano for processing.  
- The PID controller calculates the tracking error between the robot and the center of the line.  
- Based on the calculated error, correction signals are generated.  
- The motor driver adjusts the speed of the left and right motors independently for accurate steering.  
- Using continuous feedback and PID correction, the robot follows straight paths, curves, and sharp turns smoothly and efficiently.  

---

## 🧾 Development Methodology

1. Understanding the working principles of autonomous line-following robots  
2. Requirement analysis for speed, stability, and accuracy  
3. Component selection and hardware planning  
4. Designing the custom 6-channel IR sensor array  
5. Circuit design and simulation using TinkerCAD  
6. Hardware assembly and sensor placement  
7. Arduino programming and PID implementation  
8. Sensor calibration for black and white surfaces  
9. Testing and debugging on different tracks  
10. Performance optimization and stability tuning  
11. Final implementation and competition preparation  

---

## 🛠️ Technologies Used
- Arduino IDE  
- Embedded C/C++  
- PID Control Algorithm  
- TinkerCAD Circuit Simulation  
- IR Sensor Calibration Techniques  

---

## 📊 Testing & Results

### ✅ Straight Line Test
- Stable movement with minimal deviation  

### ✅ Curved Path Test
- Improved cornering and reduced overshooting  

### ✅ High-Speed Performance Test
- Maintained accurate line tracking at higher speeds  

### ✅ Sensor Accuracy Test
- Wider sensing coverage with precise positional feedback  

---

## ⚠️ Challenges Faced
- Sensor sensitivity variation  
- Oscillation at high speed  
- Sharp turn instability  
- Battery voltage fluctuation  

### ✔️ Solutions Applied
- Repeated sensor calibration  
- PID constant tuning  
- Motor speed balancing  
- Mechanical alignment improvements  

---

## 🌍 Societal Impact
- Supports industrial automation and smart transportation  
- Reduces repetitive human labor in factories and warehouses  
- Encourages robotics and embedded systems learning  
- Demonstrates practical autonomous navigation technology  
- Promotes innovation and engineering problem-solving skills  

---

## 🏆 Competition Participation
The robot was demonstrated at **Robo Expo 3.0 Line Following Robot Competition**, where the primary focus was speed, stability, and accurate tracking. Through careful sensor calibration, PID tuning, and motor optimization, the robot achieved smooth navigation and reliable autonomous performance on competitive tracks.

---

## 👨‍💻 Team Members
**Team Name:** BOD_Paradox  

- **Shadman Sarwer** — 22201242  
- **H. M. Tahsin Sheikh** — 22201243  
- **Humayra Jihan Arpita** — 22201244  

Department of Computer Science and Engineering  
**University of Asia Pacific (UAP)**  

---

## 📚 References
- Arduino Documentation  
- PID Control Research Papers  
- Robotics and Embedded Systems Journals  
- IR Sensor and Motor Driver Documentation  

---

## 📜 License
This project is licensed under the **MIT License** – feel free to use, modify, and distribute with proper credit.
