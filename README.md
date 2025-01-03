# CardioView
## Programmable Cardiac Activation Display
A comprehensive system designed to simulate and visualize cardiac activations, combining a microcontroller-based hardware model in the form of a 3d printed realistic heart model and a Python-powered graphical user interface.

## Table of Contents
1. [Project Overview](#project-overview)  
2. [Features](#features)  
3. [Hardware Design](#hardware-design)  
4. [Software Design](#software-design)  
5. [Signal Processing](#signal-processing)  

## Project Overview 
This project features a handheld cardiac activation display, combining a 3D-printed human heart model with embedded hardware and software. It showcases cardiac activity spatially and temporally through a synchronized LED matrix and graphical interface, providing insights into cardiac dysrhythmias for diagnostic applications.  
 
## Features
 **Microcontroller System**:  
   - Real-time manipulation of LEDs to depict cardiac activations on the surface of 3D Heart Model.  
   - Efficient data reception and transformation from 40-character strings into 40-byte matrices.  
   - High-speed communication via serial and Bluetooth.  

**Software**:  
   - Python-based GUI for user interaction and seamless integration with signal processing.  
   - Pan-Tompkins algorithm for real-time signal filtering and peak detection.  

**Performance**:  
   - 0.389-second data transmission time at a baud rate of 115200.
  
## Hardware Design
The microcontroller-based hardware system is the centerpiece of this project. Key components include:  
- **Microcontroller**: Interprets processed cardiac data and dynamically manipulates LED behavior.  
- **3D-Printed Heart Model**: Houses a spatially mapped LED matrix that visually represents cardiac activations, completed using Fusion 360 and Inventor  
- **Serial and Bluetooth Communication**: Facilitates high-speed, reliable data transmission between hardware and software.  

## Software Design
- Data decoding: Conversion of incoming character strings to byte matrices.  
- LED manipulation: Real-time visualization of cardiac activation patterns.  
- Seamless synchronization with Python-based software.

## Signal Processing
The Python application processes cardiac signals using:  
- **Pan-Tompkins Algorithm**:  
  - Filtering for noise reduction.  
  - Peak detection for accurate cardiac signal identification.  
  - Adaptive thresholding and search-back capabilities for robust performance.  

Processed data is transmitted to the microcontroller for LED visualization.  

