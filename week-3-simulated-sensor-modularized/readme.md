# Purpose
Menu-driven sensor bank simulator, defined by the user. Sensors can be named, have a min and max value (with validation).
Final values are printed to the console.
# Instructions
Compile and run week-3cpp
# Example Output
```
Starting up...
Program name: sensor-simulator-enhanced
Program version: 0.0.3
Program author: Dylan

Enter a name for sensor #1: Temperature
Enter the lower bound (inclusive) for Temperature: 0
Enter the upper bound (inclusive) for Temperature: 100
Enter the value for Temperature: 25
Enter a name for sensor #2: Humidity
Enter the lower bound (inclusive) for Humidity: 0
Enter the upper bound (inclusive) for Humidity: 100
Enter the value for Humidity: 85
Enter a name for sensor #3: Altitude
Enter the lower bound (inclusive) for Altitude: 0
Enter the upper bound (inclusive) for Altitude: 50000
Enter the value for Altitude: 625
Enter a name for sensor #4: Pressure
Enter the lower bound (inclusive) for Pressure: 900
Enter the upper bound (inclusive) for Pressure: 1200
Enter the value for Pressure: 1013
== Select an operation ==
a: display sensor
b: update sensor
c: display all sensors and values
d: exit
a
== Select a sensor to display==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
1
                   1 (Temperature) reading: 25
== Select an operation ==
a: display sensor
b: update sensor
c: display all sensors and values
d: exit
b
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
1
Enter the value for Temperature: 56
== Select an operation ==
a: display sensor
b: update sensor
c: display all sensors and values
d: exit
c
                   1 (Temperature) reading: 56
                   2 (Humidity) reading: 85
                   3 (Altitude) reading: 625
                   4 (Pressure) reading: 1013
== Select an operation ==
a: display sensor
b: update sensor
c: display all sensors and values
d: exit
d

Process finished with exit code 0
```