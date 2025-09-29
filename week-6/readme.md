# Purpose

Menu-driven sensor bank simulator, defined by the user. Sensors can be added as needed, including naming as well as
initial value.
Values can be updated and the updated value is printed to the console.
Final values are printed to the console.

# Requirements:

- 4 sensors types are supported: temperature, humidity, pressure, altitude.
- Exactly one sensor of each type can be added.
- Sensors can be updated once added.

# Design Considerations, Assumptions, and Limitations:

- Active sensors are tracked by a flag array, as there is only a set amount of sensor types and constraint that there
  can only be one sensor per type.
- Enum type is used for vector and array indexing, and has a underlying type of `std::size_t` for safe indexing and size
  usage
- `std::optional` is used for sensor menu selection (display and update) to get the sensorType to allow us to select the
  exit (`0`) value.

**WEEK 6 ENHANCEMENTS** 
- Updated `Sensor` struct to class. Also reorganized class and `Sensors` namespace to be a separate header and cpp class, so that Sensors can be reused outside of the context of this specific program.
- Included a `SensorBank` to track state of active sensors

# Instructions

Compile and run `main.cpp`

# Example Output

```
Starting up...
Program name: main
Program version: 0.0.6
Program author: Dylan

== Create a new sensor ==
(t=temperature, h=humidity, p=pressure, a=altitude): t
Enter a name for temperature: temp
Enter the value for temp (temperature): 15
Sensor added: temperature (temp) | value: 15°F

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 2

== Select a sensor to update ==
(t=temperature, 0=back): t
Enter the value for temp (temperature): 24
temperature (temp) | value: 24°F

== Select a sensor to update ==
(t=temperature, 0=back): 0

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 4

== Create a new sensor ==
(h=humidity, p=pressure, a=altitude): p
Enter a name for pressure: pres
Enter the value for pres (pressure): 29.92
Sensor added: pressure (pres) | value: 29.92inHg

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 3

== Active sensors ==
temperature (temp) | value: 24°F
pressure (pres) | value: 29.92inHg

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 4

== Create a new sensor ==
(h=humidity, a=altitude): a
Enter a name for altitude: alt
Enter the value for alt (altitude): 15000
Sensor added: altitude (alt) | value: 15000ft

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 3

== Active sensors ==
temperature (temp) | value: 24°F
pressure (pres) | value: 29.92inHg
altitude (alt) | value: 15000ft

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 0


Process finished with exit code 0
```