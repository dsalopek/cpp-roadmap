
# 24-Week C++ and Embedded Systems Roadmap for Defense-Oriented Software

---

## Week 1 – Getting Started
**LearnCpp Chapters:**
- Chapter 0 — Introduction / Getting Started (all submodules)
- Chapter 1 — C++ Basics (all submodules)

**Deliverables:**
- [x] **CLI Program: “Simulated System Sensor”**
  **Objectives:**
1. Display a startup greeting with program name, version, and author.
2. Define three “simulated sensors” as variables (Temperature, Pressure, Humidity) with default values.
3. Sequentially prompt the user to view/update each sensor manually.
4. Validate input: reject non-numeric input and negative values when inappropriate.
    1. ==Not yet learned==
       **Requirements/Expectations:**
- Modular functions (`displaySensor()`, `updateSensor()`).
    - ==Passing sensor name is not yet learned but took snippet from AI==
- Output formatted clearly in a table.
- README describing purpose, compilation instructions, and example output.  
  **Edge Cases:** Invalid input, early exit.

---

## Week 2 – Variables, Constants, and Basic I/O
**LearnCpp Chapters:**
- Chapter 2 — C++ Basics: Functions and Files (all submodules)
- Chapter 4 — Fundamental Data Types (all submodules)
- Chapter 5 — Constants and Strings (all submodules)

**Deliverables:**
- [x] **Extended CLI Sensor Program**  
  **Objectives:**
1. Add a fourth sensor.
2. Use `const` for static metadata (program version, max sensor limits).
3. Implement simple string input to name sensors.  
   **Requirements/Expectations:**
- Functions for input validation.
- Clear formatted output.
- README update with new sensor info.  
  **Edge Cases:** Empty strings, values exceeding limits.

---

## Week 3 – Control Flow & Loops
**LearnCpp Chapters:** 8.1–8.12

**Deliverables:**
- [x] **Menu-driven Sensor Program with Loops**

**Objectives:**
1. Implement a looped menu to view and update sensors until the user chooses to exit.
2. Use `if`, `switch`, and `for`/`while` loops appropriately for menu navigation.
3. Include simple input validation for menu selections.

**Requirements/Expectations:**
- Each menu option should call a modular function (`displaySensor()`, `updateSensor()`, `exitProgram()`).
- Display current sensor readings clearly in a table format.
- Ensure program handles repeated updates correctly and exits gracefully.
- README describing menu structure, expected behavior, and example session.

**Edge Cases:** Invalid menu choice, repeated updates, premature exit.

---

## Week 4 – Pointers and References
**LearnCpp Chapters:** 12.1–12.10

**Deliverables:**
- [x] **Sensor Program Refactor with Pointers and References**

**Objectives:**
1. Refactor functions to pass sensor data by reference instead of by value.
2. Use pointers to directly modify sensor values from functions.
3. Demonstrate null pointer checks and safe dereferencing.
4. Practice `const` references for read-only access.
5. Introduce `std::optional` for safer handling of optional sensor data (C++17).

**Requirements/Expectations:**
- No memory leaks: pointers must either be stack-based or explicitly freed.
- Use references by default; only use pointers where necessary.
- README should document pointer vs. reference use cases in your refactor.
- Include input validation and defensive programming practices appropriate for defense systems.

**Edge Cases:** Null pointers, dangling references, multiple references to the same object, missing/optional sensor data.

---

## Week 5 – Arrays, Enums, and Structs
**LearnCpp Chapters:** 13.7–13.15, 16.1–16.6, 17.1–17.5

**Deliverables:**
- [x] **Sensor Program Using Arrays, Enums, and Structs**

**Objectives:**
1. Store sensors in a fixed-size array (`std::array`) or `std::vector`).
2. Replace string-based sensor types with `enum class` for type safety.
3. Define a `Sensor` struct containing name, type, value, and units.
4. Iterate over sensors to display and update readings dynamically.
5. Strongly type sensor flags using `enum class` for bitmask operations later (prepares for Week 7).

**Requirements/Expectations:**
- Support addition of a new sensor dynamically if using `std::vector`.
- Validate user input when updating sensor values.
- README should explain array vs. vector choice, enum mapping, and iteration logic.
- Follow defensive coding practices for invalid or missing data.

**Edge Cases:** Empty arrays/vectors, invalid enum input, out-of-bounds access.

---

## Week 6 – Structs and Classes
**LearnCpp Chapters:** 14.1–14.10, 15.1–15.4

**Deliverables:**
- [x] **Convert Structs into Classes**

**Objectives:**
1. Convert `Sensor` struct into a class with member functions.
2. Add a constructor for initializing sensor data.
3. Add a display function as a class method.
4. Introduce `private` vs `public` members and accessors.
5. Demonstrate encapsulation for safety-critical data (avoid public mutation).

**Requirements/Expectations:**
- Encapsulate sensor data properly (no raw `public` fields).
- Use initializer lists in constructors.
- README should explain difference between structs and classes in C++.
- Defensive programming for uninitialized or invalid sensor data.

**Edge Cases:** Default constructor behavior, uninitialized class members, attempts to bypass encapsulation.

---

## Week 7 – Bitwise Operations and Scope
**LearnCpp Chapters:** O.1–O.4, 7.1–7.8

**Deliverables:**
- [x] **Bitwise Sensor Flags and Scope Demonstrations**

**Objectives:**
1. Use bitwise flags to represent multiple sensor states (e.g., ERROR, ACTIVE, DISABLED).
2. Demonstrate bitwise operations (`&`, `|`, `^`, `~`) on sensor state.
3. Add program output showing how local vs global scope affects sensor values.
4. Show shadowing and linkage effects by splitting code across files.
5. Integrate Week 5 `enum class` bit flags for safer and more robust state representation.

**Requirements/Expectations:**
- Use enums with bit flags for sensor states.
- Demonstrate how `static` and global variables behave differently from locals.
- README should explain bitmask design and C++ scope/linkage rules.
- Defensive handling of invalid bitmask values.

**Edge Cases:** Invalid bitmask states, shadowed variables, accidental global modifications.

---

## Week 8 – File I/O
**LearnCpp Chapters:** 28.1–28.6

**Deliverables:**
- [ ] **Persistent Sensor Program**

**Objectives:**
1. Save sensor readings to a CSV or text file.
2. Load previous sensor readings on program start.
3. Handle missing or corrupted files gracefully.
4. Use RAII (`std::ifstream`, `std::ofstream`) to ensure safe file handling.

**Requirements/Expectations:**
- Functions for `saveSensors()` and `loadSensors()`.
- Output formatting consistent with sensor table display.
- README documents file format, location, and usage examples.
- Defensive programming: handle file errors, empty files, malformed lines.

**Edge Cases:** File not found, empty file, malformed content, file permissions issues.

---

## Week 9 – Function Overloading and Templates
**LearnCpp Chapters:** 11.1–11.10

**Deliverables:**
- [ ] **Overloaded/Templated Sensor Update Functions**

**Objectives:**
1. Implement overloaded `updateSensor()` functions for `int`, `float`, and `string` values.
2. Template version for handling multiple sensor types generically.
3. Ensure type safety with C++17 features (e.g., `if constexpr` if needed).

**Requirements/Expectations:**
- Maintain existing menu and display structure.
- README documents which overload/template is called for each type.
- Defensive checks for invalid input types or values.

**Edge Cases:** Ambiguous function calls, invalid template usage, runtime type misuse.

---

## Week 10 – Dynamic Memory & Smart Pointers
**LearnCpp Chapters:** 19.1–19.4, 22.1–22.6

**Deliverables:**
- [ ] **Dynamic Sensor Storage with Smart Pointers**

**Objectives:**
1. Store sensor objects dynamically using `std::unique_ptr` or `std::shared_ptr`.
2. Demonstrate dynamic addition/removal of sensors.
3. Avoid raw pointer usage except where strictly necessary.

**Requirements/Expectations:**
- Prevent memory leaks and dangling pointers.
- README explains ownership semantics, lifetime management, and best practices.
- Defensive handling for null/shared pointer misuse.

**Edge Cases:** Improper memory deallocation, pointer misuse, shared ownership conflicts.

---

## Week 11 – Exception Handling
**LearnCpp Chapters:** 27.1–27.10

**Deliverables:**
- [ ] **Robust Sensor Program with Exceptions**

**Objectives:**
1. Wrap file I/O, input parsing, and sensor updates in `try/catch` blocks.
2. Provide meaningful error messages without crashing.
3. Ensure safe recovery and program continuation for non-critical errors.

**Requirements/Expectations:**
- Document handled exceptions and sample outputs in README.
- Defensive programming: prevent program from exiting on recoverable errors.

**Edge Cases:** Invalid numeric input, missing files, null pointer operations.

---

## Week 12 – Operator Overloading
**LearnCpp Chapters:** 21.1–21.14

**Deliverables:**
- [ ] **Custom Sensor Operations**

**Objectives:**
1. Overload `+` to combine sensor readings meaningfully.
2. Overload `<<` for human-readable sensor printing.
3. Maintain class encapsulation while overloading operators.

**Requirements/Expectations:**
- README documents operator behavior and usage examples.
- Defensive programming for incompatible sensor types or invalid combinations.

**Edge Cases:** Invalid additions, type mismatches, out-of-range results.

---

## Week 13 – Inheritance
**LearnCpp Chapters:** 24.1–24.6

**Deliverables:**
- [ ] **Derived Sensor Classes**

**Objectives:**
1. Base `Sensor` class; derive `TemperatureSensor`, `PressureSensor`, etc.
2. Override update/display methods where necessary.
3. Ensure safe polymorphic behavior with proper destructors.

**Requirements/Expectations:**
- README includes UML class hierarchy diagram.
- Defensive coding: prevent slicing, enforce virtual destructors.

**Edge Cases:** Incorrect base/derived function calls, slicing, misuse of derived types.

---

## Week 14 – Virtual Functions & Polymorphism
**LearnCpp Chapters:** 25.1–25.7

**Deliverables:**
- [ ] **Polymorphic Sensor Program**

**Objectives:**
1. Use base class pointers to manipulate derived sensor objects.
2. Demonstrate virtual function overriding and dynamic dispatch.
3. Avoid undefined behavior with proper object lifetimes.

**Requirements/Expectations:**
- Maintain menu and update/display structure.
- README demonstrates polymorphic behavior with examples.

**Edge Cases:** Improper object slicing, virtual call misuse, dangling pointers to derived objects.

---

## Week 15 – Templates and Classes
**LearnCpp Chapters:** 26.1–26.6

**Deliverables:**
- [ ] **Generic Sensor Container**

**Objectives:**
1. Create template class for storing sensors of any type.
2. Implement functions to iterate and update contained sensors.
3. Utilize `constexpr` and `if constexpr` where useful (C++17).

**Requirements/Expectations:**
- README explains template usage and type safety.
- Preserve menu and display behavior.

**Edge Cases:** Template misuse, type incompatibility, invalid instantiation.

---

## Week 16 – Advanced I/O & Random Data
**LearnCpp Chapters:** 8.13–8.15, 28.4–28.5

**Deliverables:**
- [ ] **Simulated Sensor Data Streams**

**Objectives:**
1. Generate random sensor readings for all sensors.
2. Save simulated logs to file and read back for display.
3. Use `<random>` C++17 facilities safely and deterministically for testing.

**Requirements/Expectations:**
- Maintain consistent file format and reproducible tests.
- README documents random generation methods and sample outputs.

**Edge Cases:** Invalid/randomized input, file I/O errors, out-of-range random values.

---

## Week 17 – Integrating Multiple Data Sources
**Deliverables:**
- [ ] **Sensor Aggregator Program**

**Objectives:**
1. Read multiple simulated sensor files.
2. Merge readings and compute average/min/max per sensor type.
3. Display aggregated summary table.
4. Handle missing or inconsistent data defensively.

**Requirements/Expectations:**
- Modular functions for reading, merging, reporting.
- README documents file formats and algorithms used.

**Edge Cases:** Missing/empty files, inconsistent timestamps, duplicate data.

---

## Week 18 – Hardware Interfacing Introduction
**Resources:** STM32 Blue Pill / Raspberry Pi Pico tutorials (C++ SDK, GPIO, ADC examples)

**Deliverables:**
- [ ] **Hardware Sensor Read CLI**

**Objectives:**
1. Connect to a real temperature or humidity sensor.
2. Read a single value and display on CLI.
3. Implement error checks for invalid readings and disconnected sensors.

**Requirements/Expectations:**
- Correct initialization of MCU peripherals.
- README includes wiring diagram and initialization steps.

**Edge Cases:** Sensor disconnected, invalid reading, initialization failure.

---

## Week 19 – Periodic Sensor Reads
**Deliverables:**
- [ ] **Sensor Polling Program**

**Objectives:**
1. Poll hardware sensors at fixed intervals.
2. Display updated readings continuously.
3. Implement safe polling with minimal CPU usage.

**Requirements/Expectations:**
- Use simple delay loop or `std::chrono` timing.
- README documents timing and wiring notes.

**Edge Cases:** Sensor disconnect, polling delay errors, missed reads.

---

## Week 20 – Multiple Sensors Hardware
**Deliverables:**
- [ ] **Multi-Sensor Interface Program**

**Objectives:**
1. Read multiple sensors from hardware.
2. Aggregate and display data.
3. Handle sensor-specific failure cases defensively.

**Requirements/Expectations:**
- Modular design per sensor type.
- README includes wiring diagram for all sensors.

**Edge Cases:** Disconnected sensors, invalid readings, communication errors.

---

## Week 21 – Data Logging & File Output
**Deliverables:**
- [ ] **Hardware Data Logger**

**Objectives:**
1. Save multi-sensor readings to CSV/log file.
2. Include timestamps for each reading.
3. Ensure atomic writes to prevent corrupted logs.

**Requirements/Expectations:**
- Handle file errors gracefully.
- README includes file format documentation and timestamp handling.

**Edge Cases:** File write failures, timestamp errors, partial writes.

---

## Week 22 – Sensor System with Status Encoding
**Deliverables:**
- [ ] **Hardware Sensor Program with Bitwise Status**

**Objectives:**
1. Combine hardware readings with 32-bit status word for each sensor.
2. Display human-readable status along with readings.
3. Implement error/warning/health field updates.
4. Use `enum class` bit flags for type-safe status.

**Requirements/Expectations:**
- Modular functions for bitwise set/get/clear.
- README includes field mapping and examples.
- Defensive coding for invalid status updates or corrupted bits.

**Edge Cases:** Invalid field updates, bit corruption, conflicting flags.

---

## Week 23 – Multi-Sensor Aggregation and Display
**Deliverables:**
- [ ] **Hardware Aggregator CLI**

**Objectives:**
1. Poll multiple sensors continuously.
2. Aggregate readings (min, max, average) and status flags.
3. Display in CLI table with real-time updates.
4. Handle disconnections or read errors gracefully.

**Requirements/Expectations:**
- Modular aggregation functions.
- README documents display format, calculation method, and polling interval.

**Edge Cases:** Sensor disconnect, invalid readings, inconsistent status flags.

---

## Week 24 – Capstone: Full Defense-Oriented Sensor System
**Deliverables:**
- [ ] **Complete Multi-Sensor System with Hardware Integration**

**Objectives:**
1. Connect multiple sensors via STM32 or Pico.
2. Continuous polling, aggregation, logging, and status bit encoding.
3. Display summary statistics (min/max/average) and bitwise status on CLI.
4. Handle disconnected sensors, invalid readings, and error states.
5. Create supporting diagrams:
    - Wiring and pin connections
    - Data flow
    - Modular software architecture
6. Include README with:
    - Build/run instructions
    - Hardware setup
    - Explanation of bitwise status encoding and aggregation logic
    - Example output session
7. Ensure safe operation in a defense-grade environment with fault tolerance and robust error handling.

**Edge Cases:** Sensor failures, corrupted readings, concurrent hardware errors, CLI display inconsistencies.
