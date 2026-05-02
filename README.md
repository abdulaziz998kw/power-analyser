# Power Quality Waveform Analyser

##  Overview

This project is a C-based command-line application for analysing power quality waveform data from a CSV file.

It processes waveform samples and computes key electrical metrics such as RMS, peak-to-peak voltage, DC offset, clipping, and statistical values. The application is structured using modular C design and is developed using **CLion**.

---

##  Features

* CSV file input using file I/O

* Dynamic memory allocation (`malloc` / `free`)

* Modular design using `.c` and `.h` files

* Waveform analysis functions:

  * RMS voltage
  * Peak-to-peak voltage
  * DC offset
  * Clipping detection
  * Compliance checking
  * Mean and standard deviation

* Bitwise status encoding

* Results exported to `results.txt`

---

##  Key Concepts

* Pointers and arrays
* Dynamic memory management
* Modular programming
* Signal processing basics
* Bitwise operations (status flags)

---

##  Project Structure

```
.
├── main.c
├── io.c
├── io.h
├── waveform.c
├── waveform.h
├── results.txt
├── README.md
```

##  Build Instructions (CLion)

This project is intended to be built using **CLion with CMake**.

### Steps:

1. Open the project folder in CLion
2. Ensure a `CMakeLists.txt` exists (CLion may generate it automatically)
3. Build the project using the **Build** button

---

## Running the Program

The program expects a CSV file as input:

```
./program_name input_file.csv
```

Example:

```
./power-analyser data.csv
```

---

##  Output

The program generates:

```
results.txt
```

Which includes:

* RMS values
* Peak-to-peak values
* DC offset
* Clipping counts
* Compliance results
* Mean and standard deviation
* Status flags

---

##  Status Flags

Each waveform has a status value encoded as:

* Bit 0 → Clipping detected
* Bit 1 → RMS out of compliance

Examples:

* `0` → OK
* `1` → Clipping only
* `2` → Compliance issue only
* `3` → Both issues

---

##  Testing

Tested using:

* Valid CSV input
* Invalid/missing file input
* Edge cases (empty or small datasets)

---

##  Error Handling

* File opening validation
* Memory allocation checks
* Safe termination on failure

---

##  Notes

This project demonstrates practical C programming applied to signal processing and data analysis, with a focus on clean structure, modularity, and realistic workflow development.

---
