# Objective
The objective is to make led glow whenever something passes across the sensor, as shown in the demonstration video.

# Components
- Arduino Uno: 1
- Ultrasonic Sensor: 1
- Jumper Wires: 1
- Led: 1
- Resistor: 1
- Power source (battery or laptop): 1

# Idea
The logic is if the magnitude of difference between the current distance and the previous distance, measured by the ultrasonic sensor, is more than the threshold value, then make the led glow.

# Requirement
- Newping.h
