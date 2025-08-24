# Configurable Data Processing System

## Overview
A C++ application demonstrating OOP, STL, templates, file handling, and exception handling. Processes data based on a JSON configuration file using polymorphism and the Factory Design Pattern.

## Features
- Parses `settings.json` for dynamic configuration.
- Abstract `Processor` with derived classes (`Text`, `Numeric`, `Image`, `Audio`).
- `ProcessorFactory` for dynamic object creation.
- Template-based data processing.
- Robust error handling.

## Project Structure
```
ConfigurableProcessor/
├── include/
│   ├── Processor.hpp
│   ├── ProcessorFactory.hpp
│   ├── Configuration.hpp
│   ├── Utilities.hpp
├── src/
│   ├── Processor.cpp
│   ├── ProcessorFactory.cpp
│   ├── Configuration.cpp
│   ├── main.cpp
├── config/
│   ├── settings.json
├── Makefile
├── README.md
```

## Prerequisites
- C++11 compiler (e.g., `g++`)
- Make

## Installation
1. Clone the repository.
2. Navigate to `ConfigurableProcessor/`.
3. Build the project:
   ```bash
   make all
   ```

## Usage
1. Edit `config/settings.json`:
   ```json
   {
     "Processor": {
       "Options": {
         "Type": "Image",
         "Threshold": 0.5,
         "MaxRetries": 3
       }
     }
   }
   ```
2. Run:
   ```bash
   ./ConfigurableProcessor
   ```

## Clean Up
```bash
make clean
```

## License
MIT License