# Purpose
Menu-driven sensor bank simulator, defined by the user. Sensors can be named, have a min and max value (with validation).
Final values are printed to the console.
Includes references and std::optional for adding/updating values. std::optional is used to optionally add another sensor
# Instructions
Compile and run week.cpp
# Example Output
```
Starting up...
Program name: main
Program version: 0.0.4
Program author: Dylan

Enter a name for sensor #1: Temperature
0x7ffdc0766380Enter the lower bound (inclusive) for Temperature: 0
Enter the upper bound (inclusive) for Temperature: 112
Enter the value for Temperature: 77
Enter a name for sensor #2: Humidity
Enter the lower bound (inclusive) for Humidity: 0
Enter the upper bound (inclusive) for Humidity: 100
Enter the value for Humidity: 34
Enter a name for sensor #3: Altitude
Enter the lower bound (inclusive) for Altitude: 0
Enter the upper bound (inclusive) for Altitude: 10000
Enter the value for Altitude: 625
Enter a name for sensor #4: Pressure
Enter the lower bound (inclusive) for Pressure: 800
Enter the upper bound (inclusive) for Pressure: 1200
Enter the value for Pressure: 1017
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
4: add another sensor 
0: exit
1
== Select a sensor to display==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
0: back
1
Temperature (# 1) reading: 77
== Select a sensor to display==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
0: back
2
Humidity (# 2) reading: 34
== Select a sensor to display==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
0: back
0
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
4: add another sensor 
0: exit
2
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
0: back
1
Enter the value for Temperature: 78
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
0: back
0
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
4: add another sensor 
0: exit
3
Temperature (# 1) reading: 78
Humidity (# 2) reading: 34
Altitude (# 3) reading: 625
Pressure (# 4) reading: 1017
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
4: add another sensor 
0: exit
4
Enter a name for sensor #5: Azimuth
Enter the lower bound (inclusive) for Azimuth: 0
Enter the upper bound (inclusive) for Azimuth: 360
Enter the value for Azimuth: 184
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
1
== Select a sensor to display==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
5: Azimuth
0: back
0
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
2
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
5: Azimuth
0: back
0
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
3
Temperature (# 1) reading: 78
Humidity (# 2) reading: 34
Altitude (# 3) reading: 625
Pressure (# 4) reading: 1017
Azimuth (# 5) reading: 184
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
2
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
5: Azimuth
0: back
5
Enter the value for Azimuth: 269
== Select a sensor to update==
1: Temperature
2: Humidity
3: Altitude
4: Pressure
5: Azimuth
0: back
0
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
3
Temperature (# 1) reading: 78
Humidity (# 2) reading: 34
Altitude (# 3) reading: 625
Pressure (# 4) reading: 1017
Azimuth (# 5) reading: 269
== Select an operation ==
1: display sensor
2: update sensor
3: display all sensors and values
0: exit
0

Process finished with exit code 0
```