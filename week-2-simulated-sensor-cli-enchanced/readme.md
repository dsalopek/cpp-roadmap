# Purpose
To simulate 4 sensors, defined by the user. Sensors can be named, have a min and max value (with validation).
Final values are printed to the console.
# Instructions
Compile and run sensor-simulator-enhanced.cpp
# Example Output
```
Starting up...
Program name: sensor-simulator-enhanced
Program version: 0.0.2
Program author: Dylan

Enter a name for sensor #1: Temperature
Enter the lower bound (inclusive) for Temperature: 0
Enter the upper bound (inclusive) for Temperature: 120

Enter a name for sensor #2: Humidity
Enter the lower bound (inclusive) for Humidity: 0
Enter the upper bound (inclusive) for Humidity: 100

Enter a name for sensor #3: Altitude
Enter the lower bound (inclusive) for Altitude: 0
Enter the upper bound (inclusive) for Altitude: 50000

Enter a name for sensor #4: Pressure
Enter the lower bound (inclusive) for Pressure: 900
Enter the upper bound (inclusive) for Pressure: 1100

Enter the value for Temperature: -5
You must input a value between 0 and 120 (inclusive). Try again: 15

Enter the value for Humidity: 65

Enter the value for Altitude: 1500

Enter the value for Pressure: 1013

                   1 (Temperature) reading: 15
                   2 (Humidity) reading: 65
                   3 (Altitude) reading: 1500
                   4 (Pressure) reading: 1013
```