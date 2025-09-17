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

# Instructions

Compile and run `main.cpp`

# Example Output

```
Starting up...
Program name: main
Program version: 0.0.5
Program author: Dylan

== Create a new sensor ==
(t=temperature, h=humidity, p=pressure, a=altitude): 1
Invalid selection. Try again: t
Enter a name for temperature: t1
Enter the value for t1 (temperature): 123
Sensor added: temperature (t1) | value: 123C

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 1

== Select a sensor to display ==
(t=temperature, 0=back): t
temperature (t1) | value: 123C

== Select a sensor to display ==
(t=temperature, 0=back): 0

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 3

== Active sensors ==
temperature (t1) | value: 123C

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 4

== Create a new sensor ==
(h=humidity, p=pressure, a=altitude): h
Enter a name for humidity: h1
Enter the value for h1 (humidity): 59
Sensor added: humidity (h1) | value: 59%

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 3

== Active sensors ==
temperature (t1) | value: 123C
humidity (h1) | value: 59%

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 2

== Select a sensor to update ==
(t=temperature, h=humidity, 0=back): h
Enter the value for h1 (humidity): 43
humidity (h1) | value: 43%

== Select a sensor to update ==
(t=temperature, h=humidity, 0=back): 0

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 3

== Active sensors ==
temperature (t1) | value: 123C
humidity (h1) | value: 43%

== Select an operation ==
(1=display sensor, 2=update sensor, 3=display all sensors and values, 4=add another sensor, 0=exit): 0


Process finished with exit code 0
```