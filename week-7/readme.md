# Purpose

Console-based sensor management program. Allows the user to add, update, and display sensors for temperature, humidity,
pressure, and altitude.

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

**WEEK 7 Changelog**
- Allow unlimited sensors to be added instead of 1 of each type
- Included bit flags to track sensor status (and update too)

# Instructions

Compile and run `main.cpp`

# Example Output

```
Starting up...
Program name: main
Program version: 0.0.7
Program author: Dylan

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 2

== Select a sensor to update ==
No sensors found. Please add one to update.

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
No sensors found. Please add one to view.

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
> 1
Enter a name for temperature
> t1
Enter a value for t1 (temperature °F)
> 112
Sensor added: temperature (t1) | value: 112°F | status flags: [Enabled, Online, Healthy, Nominal]

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
> 1
Enter a name for temperature
> t2
Enter a value for t2 (temperature °F)
> 155
Sensor added: temperature (t2) | value: 155°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (t1) | value: 112°F | status flags: [Enabled, Online, Healthy, Nominal]
temperature (t2) | value: 155°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 2

== Select a sensor to update ==
1=t1 (temperature)
2=t2 (temperature)
0=back
> 1
Select an option
1=name
2=value
3=disable
0=back
> 1
Enter a name for temperature
> t1.1
Sensor updated: temperature (t1.1) | value: 112°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=t1.1 (temperature)
2=t2 (temperature)
0=back
> 1
Select an option
1=name
2=value
3=disable
0=back
> 2
Enter a value for t1.1 (temperature °F)
> 212
Sensor updated: temperature (t1.1) | value: 212°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=t1.1 (temperature)
2=t2 (temperature)
0=back
> 1
Select an option
1=name
2=value
3=disable
0=back
> 3
Sensor updated: temperature (t1.1) | value: 212°F | status flags: [Disabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=t1.1 (temperature)
2=t2 (temperature)
0=back
> 0

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 3

== Active sensors ==
temperature (t1.1) | value: 212°F | status flags: [Disabled, Online, Healthy, Nominal]
temperature (t2) | value: 155°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 2

== Select a sensor to update ==
1=t1.1 (temperature)
2=t2 (temperature)
0=back
> 1
Select an option
1=name
2=value
3=enable
0=back
> 3
Sensor updated: temperature (t1.1) | value: 212°F | status flags: [Enabled, Online, Healthy, Nominal]

== Select a sensor to update ==
1=t1.1 (temperature)
2=t2 (temperature)
0=back
> 0

== Select an operation ==
1=add new sensor
2=update sensors
3=display all sensors
0=exit
> 0

Exiting...
```