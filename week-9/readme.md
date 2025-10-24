# Purpose

Console-based sensor management program. Allows the user to add, update, and display sensors for temperature, humidity,
pressure, and altitude. Reads and stores sensor data for next use in CSV format.

# Requirements:

- 4 sensors types are supported: temperature, humidity, pressure, altitude.
- Unlimited sensors can be added.
- Sensors can be updated once added.
    - name
    - value
    - disable/enable
- Sensors can be displayed

# Design Considerations, Assumptions, and Limitations:

- Active sensors are kept in a vector since any amount of sensors can be added.
- Sensor metadata (aggregation of sensor data per sensor type) is stored in a struct
- Input is validated, ie for ints (menu selections), doubles (sensor values), and strings (sensor names)
- Sensor flags are tracked as bits in a `std::uint8_t` var, which allows us to perform bitwise operations on the
  flags. (for now just enable/disable and checking if the sensor status is in a 'good' state)

**WEEK 8 Changelog**
- **Add persistence in the form of CSV**
- **Add TestSuite for persistence**

# Instructions
Make rules:
- To build executable `make build`
- To build test executable `make build-test`
- To run executable `make run`
- To run test executable `make test`
- To clean up builds `make clean` 
  - Warning this cleans up GoogleTest local build

# Example Output

```
(base) sokoban@ads:~/eightystechnologies/cpp-roadmap/week-8$ make run
./build/application
Starting up...
Program name: main
Program version: 0.0.8
Program author: Dylan

Attempting to load existing sensor data from file: data.csv
File already exists

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (T1) | value: 100°F | status flags: [Enabled, Online, Healthy, Nominal]
humidity (h1) | value: 10% | status flags: [Enabled, Online, Healthy, Nominal]
pressure (P1) | value: 29.92inHg | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 1

== Select a sensor type to create ==
1=temperature
2=humidity
3=altitude
4=pressure
0=back
> 3
Enter a name for altitude
> A1
Enter a value for A1 (altitude ft)
> 15000
Sensor added: altitude (A1) | value: 15000ft | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (T1) | value: 100°F | status flags: [Enabled, Online, Healthy, Nominal]
humidity (h1) | value: 10% | status flags: [Enabled, Online, Healthy, Nominal]
pressure (P1) | value: 29.92inHg | status flags: [Enabled, Online, Healthy, Nominal]
altitude (A1) | value: 15000ft | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 2

== Select a sensor to update ==
1=T1 (temperature)
2=h1 (humidity)
3=P1 (pressure)
4=A1 (altitude)
0=back
> 1
Select an option
1=name
2=value
3=disable
0=back
> 1
Enter a name for temperature
> temp1
Sensor updated: temperature (temp1) | value: 100°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=temp1 (temperature)
2=h1 (humidity)
3=P1 (pressure)
4=A1 (altitude)
0=back
> 1
Select an option
1=name
2=value
3=disable
0=back
> 2
Enter a value for temp1 (temperature °F)
> 105
Sensor updated: temperature (temp1) | value: 105°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=temp1 (temperature)
2=h1 (humidity)
3=P1 (pressure)
4=A1 (altitude)
0=back
> 2
Select an option
1=name
2=value
3=disable
0=back
> 3
Sensor updated: humidity (h1) | value: 10% | status flags: [Disabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=temp1 (temperature)
2=h1 (humidity)
3=P1 (pressure)
4=A1 (altitude)
0=back
> 0

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (temp1) | value: 105°F | status flags: [Enabled, Online, Healthy, Nominal]
humidity (h1) | value: 10% | status flags: [Disabled, Online, Healthy, Nominal]
pressure (P1) | value: 29.92inHg | status flags: [Enabled, Online, Healthy, Nominal]
altitude (A1) | value: 15000ft | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 0

Exiting...

Saving sensor data to file: data.csv
(base) sokoban@ads:~/eightystechnologies/cpp-roadmap/week-8$ make run
./build/application
Starting up...
Program name: main
Program version: 0.0.8
Program author: Dylan

Attempting to load existing sensor data from file: data.csv
File already exists

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (temp1) | value: 105°F | status flags: [Enabled, Online, Healthy, Nominal]
humidity (h1) | value: 10% | status flags: [Disabled, Online, Healthy, Nominal]
pressure (P1) | value: 29.92inHg | status flags: [Enabled, Online, Healthy, Nominal]
altitude (A1) | value: 15000ft | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 0

Exiting...

Saving sensor data to file: data.csv
Save was successful.
```