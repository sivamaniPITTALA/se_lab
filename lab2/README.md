# Student Result Processing System v2.0

## Overview
A modular C-based Student Result Processing System developed for Software Engineering Lab. This version (v2.0) incorporates modularization, quality characteristics, documentation, and testing.

## Features

### Modular Design
The system is divided into 3 modules:

1. **Student Module** (`student.h`, `student.c`)
   - Add, display, search, update, delete students
   - Data validation

2. **Result Module** (`result.h`, `result.c`)
   - Course marks management
   - Grade calculation (A+, A, B+, B, C, F)
   - Pass/fail status determination

3. **File I/O Module** (`file_io.h`, `file_io.c`)
   - Binary file storage
   - CSV export for interoperability

### Quality Characteristics

| Characteristic | Implementation |
|----------------|----------------|
| **Usability** | Menu-driven interface, clear error messages, validation feedback |
| **Efficiency** | Static allocation, O(n) algorithms, binary file format |
| **Reusability** | Modular design, library creation (`make compile_library`) |
| **Interoperability** | CSV export, data exchange functions |

## Building the System

```bash
# Compile the entire system
make

# Compile and run
make run

# Create static library
make compile_library

# Clean build files
make clean

# Display module information
make info

# Show help
make help
```

## Usage

1. Run the compiled program:
   ```bash
   ./student_result_system
   ```

2. Use the menu to:
   - Add/view/search/update/delete students
   - Add/view results and calculate grades
   - Save/load data from files
   - Export to CSV for Excel/spreadsheet compatibility

## Module Specifications

See `MODULE_SPECIFICATION.md` for detailed documentation including:
- Algorithm pseudocode
- Flowcharts
- Input/Pre-condition/Output for each function

## Test Plan

See `TEST_PLAN.md` for:
- 25 test cases covering all modules
- Integration tests
- Expected vs actual output tracking

## Files

```
lab2/
├── student.h          # Student module header
├── student.c          # Student module implementation
├── result.h           # Result module header
├── result.c           # Result module implementation
├── file_io.h          # File I/O module header
├── file_io.c          # File I/O module implementation
├── main.c             # Main application
├── Makefile           # Build configuration
├── README.md          # This file
├── MODULE_SPECIFICATION.md   # Detailed module docs
└── TEST_PLAN.md       # Test cases and results
```

## Grade Boundaries

| Percentage | Grade |
|------------|-------|
| 90-100 | A+ |
| 80-89 | A |
| 70-79 | B+ |
| 60-69 | B |
| 50-59 | C |
| 0-49 | F |

## Submission

- GitHub repository: [To be added]
- Submission Date: January 22, 2026

## Author

Student Developer
M.Tech (CS, AI) 2025-26
School of Computer and Information Sciences

