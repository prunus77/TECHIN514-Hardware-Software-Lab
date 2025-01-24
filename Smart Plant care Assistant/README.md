
# Smart Plant Care Assistant
As plant owners we often forget to give good care to the plants. This project monitors soil moisture, temperature, and ambient light to provide actionable insights for optimal plant care. 

The system uses sensors to collect data and a display device for real-time feedback.
Below is the sketch to the conceotual sketch of the device system:

![Concept_Image](https://github.com/prunus77/TECHIN514-Hardware-Software-Lab/blob/main/Smart%20Plant%20care%20Assistant/Pictures/Concept%20Sketch.jpg)

## Sensor Device
The sensor device collects environmental data using soil moisture, temperature, and ambient light sensors. It sends this data via BLE to the display device. The sensors are powered by a rechargeable battery with USB charging capabilities.

Below are the features of the Sensor Device:

- Sensors: Soil moisture, temperature, ambient light.
- Wireless module: Bluetooth Low Energy (BLE).
- Power source: Rechargeable battery.
- Enclosure: Portable and weather-resistant.
 
Below is the Picture:
![Sensing_Device](https://github.com/prunus77/TECHIN514-Hardware-Software-Lab/blob/main/Smart%20Plant%20care%20Assistant/Pictures/Sensing%20Device.png)


## Display Device
The display device receives data from the sensor device via BLE and visualizes it. A gauge needle shows soil moisture levels, LEDs indicate environmental conditions (e.g., too hot, too dry), and a button allows users to interact with the system. The device is powered by a thoughtfully sized battery with USB charging.

Below are the features of the Sensor Device:
![Display_Device](https://github.com/prunus77/TECHIN514-Hardware-Software-Lab/blob/main/Smart%20Plant%20care%20Assistant/Pictures/Display%20Device.png)

- Stepper motor-driven needle gauge: Indicates the level of care needed
- LED indicators: Indicates the if plant needs watering
- Button for user interactions: Users can reset the specific plants reminder on the disply when care has been given to the plant
- Enclosure design: Will Probably be made out of wood. And will have magnets to stick on metalic surfaces of daily use such as refrigerator door.


## Communication and System Diagram
- Figure 1: Communication diagram showing how the sensor and display devices interact via BLE.
![Cloud_Architecture](https://github.com/prunus77/TECHIN514-Hardware-Software-Lab/blob/main/Smart%20Plant%20care%20Assistant/Pictures/Cloud%20Architecture.png)

- Figure 2: Detailed system architecture showing sensors, microcontroller, wireless communication, and power flow.
![Flowchart](https://github.com/prunus77/TECHIN514-Hardware-Software-Lab/blob/main/Smart%20Plant%20care%20Assistant/Pictures/System%20Architecture%20flowchart.png)
