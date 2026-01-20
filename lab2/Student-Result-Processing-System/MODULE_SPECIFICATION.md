================================================================================
                    STUDENT RESULT PROCESSING SYSTEM
                     MODULE SPECIFICATION DOCUMENT
                    Software Engineering Lab - Task 2
================================================================================

Document Version: 2.0
Date: January 2026
Author: Student Developer

================================================================================
                         TABLE OF CONTENTS
================================================================================
1. Module Overview
2. Module 1: Student Management
3. Module 2: Result Processing
4. Module 3: File I/O
5. Module Dependencies
6. Quality Characteristics Implementation

================================================================================
                         1. MODULE OVERVIEW
================================================================================

The Student Result Processing System is divided into 3 modules:

Module Characteristics:
  ✓ Each module has a unique name
  ✓ Can be separately compiled and stored in a library
  ✓ Modules can call other modules (low coupling)
  ✓ High cohesion - each module has single responsibility

Module Diagram:
  +------------------+
  |     MAIN.C       |  <-- Application entry point
  +--------+---------+
           |
  +--------+---------+--------+--------+
  |                  |                  |
  +--------+---------+--------+--------+
  |   STUDENT        |   RESULT         |  <-- Core modules
  |   MODULE         |   MODULE         |
  +--------+---------+--------+--------+
           |                  |
  +--------+---------+--------+--------+
  |                  |                  |
  +--------+---------+--------+--------+
  |   FILE I/O       |                  |  <-- Support module
  |   MODULE         |                  |
  +------------------+------------------+

================================================================================
                    2. MODULE: STUDENT MANAGEMENT
================================================================================

Module Name: Student
File: student.h, student.c
Purpose: Handle all student data management operations
Pre-condition: Student array must be initialized
Post-condition: Student data stored/retrieved successfully

------------------------------------------------------------------------------
FUNCTION: add_student
------------------------------------------------------------------------------

Module Name: add_student
Input: 
  - students[]: Array of Student structures
  - count: Pointer to current student count
  - new_student: Student data to add
Pre-condition:
  - Array must be initialized
  - count pointer must be valid
  - Array must not be full (count < MAX_STUDENTS)

Algorithm (Pseudocode):
```
FUNCTION add_student(students, count, new_student):
    // Efficiency: Check capacity first
    IF *count >= MAX_STUDENTS THEN
        PRINT "Error: Maximum student limit reached!"
        RETURN 0
    
    // Validation: Check required fields
    IF NOT validate_student_data(new_student) THEN
        PRINT "Error: Invalid student data!"
        RETURN 0
    
    // Check for duplicate ID
    FOR i FROM 0 TO *count - 1 DO
        IF students[i].student_id == new_student.student_id THEN
            PRINT "Error: Student with ID %d already exists!"
            RETURN 0
    
    // Add student to array
    students[*count] = new_student
    *count = *count + 1
    
    RETURN 1
END FUNCTION
```

Input Example:
  student_id: 1001
  name: "John Smith"
  age: 22
  program: "MTech-CS"

Output:
  - Success: 1 (TRUE)
  - Failure: 0 (FALSE) with error message

Complexity: O(n) where n = number of students

------------------------------------------------------------------------------
FUNCTION: search_student
------------------------------------------------------------------------------

Module Name: search_student
Input:
  - students[]: Array of Student structures
  - count: Number of students in array
  - student_id: ID to search for
Pre-condition:
  - Array must be initialized

Algorithm (Pseudocode):
```
FUNCTION search_student(students, count, student_id):
    FOR i FROM 0 TO count - 1 DO
        IF students[i].student_id == student_id THEN
            RETURN i  // Found at index i
    
    RETURN -1  // Not found
END FUNCTION
```

Input: student_id = 1001
Output: Index (>=0) if found, -1 if not found
Complexity: O(n)

------------------------------------------------------------------------------
FUNCTION: update_student
------------------------------------------------------------------------------

Module Name: update_student
Input:
  - students[]: Array of Student structures
  - count: Number of students
  - student_id: ID of student to update
  - updated_data: New student data
Pre-condition:
  - Student with given ID must exist

Algorithm (Pseudocode):
```
FUNCTION update_student(students, count, student_id, updated_data):
    index = search_student(students, count, student_id)
    
    IF index == -1 THEN
        PRINT "Error: Student not found!"
        RETURN 0
    
    IF NOT validate_student_data(updated_data) THEN
        PRINT "Error: Invalid data!"
        RETURN 0
    
    // Update fields (preserve student_id)
    students[index].age = updated_data.age
    COPY updated_data.name TO students[index].name
    COPY updated_data.program TO students[index].program
    
    RETURN 1
END FUNCTION
```

Output: 1 for success, 0 for failure
Complexity: O(n)

------------------------------------------------------------------------------
FUNCTION: delete_student
------------------------------------------------------------------------------

Module Name: delete_student
Input:
  - students[]: Array of Student structures
  - count: Pointer to student count
  - student_id: ID of student to delete
Pre-condition:
  - Student with given ID must exist

Algorithm (Pseudocode):
```
FUNCTION delete_student(students, count, student_id):
    index = search_student(students, *count, student_id)
    
    IF index == -1 THEN
        PRINT "Error: Student not found!"
        RETURN 0
    
    // Shift elements left to fill gap
    FOR i FROM index TO *count - 2 DO
        students[i] = students[i + 1]
    
    *count = *count - 1
    
    RETURN 1
END FUNCTION
```

Output: 1 for success, 0 for failure
Complexity: O(n)

------------------------------------------------------------------------------
FUNCTION: validate_student_data
------------------------------------------------------------------------------

Module Name: validate_student_data
Input: Student structure s
Pre-condition: None

Algorithm (Pseudocode):
```
FUNCTION validate_student_data(s):
    IF s.student_id <= 0 THEN
        PRINT "  -> Error: Student ID must be positive!"
        RETURN 0
    
    IF LENGTH(s.name) == 0 THEN
        PRINT "  -> Error: Name cannot be empty!"
        RETURN 0
    
    IF s.age < 15 OR s.age > 50 THEN
        PRINT "  -> Error: Age must be between 15 and 50!"
        RETURN 0
    
    IF LENGTH(s.program) == 0 THEN
        PRINT "  -> Error: Program cannot be empty!"
        RETURN 0
    
    RETURN 1
END FUNCTION
```

Output: 1 if valid, 0 if invalid

================================================================================
                    3. MODULE: RESULT PROCESSING
================================================================================

Module Name: Result
File: result.h, result.c
Purpose: Handle student marks, grades, and result calculations
Pre-condition: Course marks must be set
Post-condition: Results calculated and stored

------------------------------------------------------------------------------
FUNCTION: calculate_grade
------------------------------------------------------------------------------

Module Name: calculate_grade
Input: percentage (float)
Pre-condition: Percentage between 0-100

Algorithm (Pseudocode):
```
FUNCTION calculate_grade(percentage):
    IF percentage >= 90 THEN RETURN "A+"
    ELSE IF percentage >= 80 THEN RETURN "A"
    ELSE IF percentage >= 70 THEN RETURN "B+"
    ELSE IF percentage >= 60 THEN RETURN "B"
    ELSE IF percentage >= 50 THEN RETURN "C"
    ELSE RETURN "F"
END FUNCTION
```

Flowchart:
                    [percentage >= 90?]
                           |
              [YES]--------+--------[NO]
               |                      |
            "A+"         [percentage >= 80?]
                              |
                 [YES]--------+--------[NO]
                  |                      |
               "A"          [percentage >= 70?]
                                   |
                      [YES]--------+--------[NO]
                       |                      |
                    "B+"         [percentage >= 60?]
                                        |
                           [YES]--------+--------[NO]
                            |                      |
                         "B"          [percentage >= 50?]
                                             |
                                [YES]--------+--------[NO]
                                 |                      |
                              "C"                     "F"

Input: percentage = 85.5
Output: "A"
Complexity: O(1)

------------------------------------------------------------------------------
FUNCTION: calculate_result
------------------------------------------------------------------------------

Module Name: calculate_result
Input: result (pointer to Result structure)
Pre-condition: Course marks must be set

Algorithm (Pseudocode):
```
FUNCTION calculate_result(result):
    total_max = 0
    total_obtained = 0
    
    FOR i FROM 0 TO result.num_courses - 1 DO
        total_max = total_max + result.courses[i].max_marks
        total_obtained = total_obtained + result.courses[i].marks_obtained
    
    result.total_marks = total_obtained
    
    IF total_max > 0 THEN
        result.percentage = (total_obtained / total_max) * 100
    ELSE
        result.percentage = 0
    
    COPY calculate_grade(result.percentage) TO result.grade
END FUNCTION
```

Input Example:
  course[0]: course_id=1, course_name="SE", max_marks=100, marks_obtained=85
  course[1]: course_id=2, course_name="DBMS", max_marks=100, marks_obtained=75
  course[2]: course_id=3, course_name="OS", max_marks=100, marks_obtained=90

Output:
  total_marks = 250
  percentage = 83.33
  grade = "A"
Complexity: O(m) where m = number of courses

------------------------------------------------------------------------------
FUNCTION: add_result
------------------------------------------------------------------------------

Module Name: add_result
Input:
  - results[]: Array of Result structures
  - count: Pointer to result count
  - new_result: Result data to add
Pre-condition:
  - Student must exist in student database

Algorithm (Pseudocode):
```
FUNCTION add_result(results, count, new_result):
    IF *count >= MAX_STUDENTS THEN
        PRINT "Error: Maximum limit reached!"
        RETURN 0
    
    // Check for duplicate
    FOR i FROM 0 TO *count - 1 DO
        IF results[i].student_id == new_result.student_id THEN
            PRINT "Error: Result already exists!"
            RETURN 0
    
    // Calculate before storing
    calculate_result(new_result)
    
    // Add to array
    results[*count] = new_result
    *count = *count + 1
    
    RETURN 1
END FUNCTION
```

Output: 1 for success, 0 for failure
Complexity: O(n + m)

------------------------------------------------------------------------------
FUNCTION: get_pass_fail
------------------------------------------------------------------------------

Module Name: get_pass_fail
Input: Result structure r
Pre-condition: Result must be calculated

Algorithm (Pseudocode):
```
FUNCTION get_pass_fail(r):
    IF r.percentage >= 50 THEN
        RETURN "Pass"
    ELSE
        RETURN "Fail"
END FUNCTION
```

Input: percentage = 65.0
Output: "Pass"
Complexity: O(1)

================================================================================
                    4. MODULE: FILE I/O
================================================================================

Module Name: File I/O
File: file_io.h, file_io.c
Purpose: Handle data persistence and interoperability
Pre-condition: Valid file path
Post-condition: Data saved to/loaded from file

------------------------------------------------------------------------------
FUNCTION: save_students_to_file
------------------------------------------------------------------------------

Module Name: save_students_to_file
Input:
  - students[]: Array of Student structures
  - count: Number of students
  - filename: Path to save file
Pre-condition:
  - File path must be writable

Algorithm (Pseudocode):
```
FUNCTION save_students_to_file(students, count, filename):
    fp = OPEN_FILE(filename, "wb")
    IF fp == NULL THEN
        PRINT "Error: Cannot open file!"
        RETURN 0
    
    // Write count first
    WRITE fp, count
    
    // Write all students
    FOR i FROM 0 TO count - 1 DO
        WRITE fp, students[i]
    
    CLOSE_FILE(fp)
    PRINT "Successfully saved %d students to %s", count, filename
    
    RETURN 1
END FUNCTION
```

Input: 3 students, filename="students.dat"
Output: Binary file created with student data
Complexity: O(n)

------------------------------------------------------------------------------
FUNCTION: load_students_from_file
------------------------------------------------------------------------------

Module Name: load_students_from_file
Input:
  - students[]: Array to store loaded students
  - count: Pointer to store loaded count
  - filename: Path to file
Pre-condition:
  - File must exist

Algorithm (Pseudocode):
```
FUNCTION load_students_from_file(students, count, filename):
    fp = OPEN_FILE(filename, "rb")
    IF fp == NULL THEN
        PRINT "Note: File not found. Starting empty."
        *count = 0
        RETURN 0
    
    // Read count
    READ fp, count
    
    // Read all students
    FOR i FROM 0 TO *count - 1 DO
        READ fp, students[i]
    
    CLOSE_FILE(fp)
    PRINT "Successfully loaded %d students", *count
    
    RETURN 1
END FUNCTION
```

Output: Students array populated, count updated
Complexity: O(n)

------------------------------------------------------------------------------
FUNCTION: export_to_csv
------------------------------------------------------------------------------

Module Name: export_to_csv
Input:
  - students[]: Student array
  - stu_count: Number of students
  - results[]: Result array
  - res_count: Number of results
  - filename: Output CSV filename
Pre-condition: None

Algorithm (Pseudocode):
```
FUNCTION export_to_csv(students, stu_count, results, res_count, filename):
    fp = OPEN_FILE(filename, "w")
    IF fp == NULL THEN
        PRINT "Error: Cannot create CSV file!"
        RETURN 0
    
    // Write CSV header
    WRITE_LINE fp, "Student_ID,Name,Age,Program,Total_Marks,Percentage,Grade,Status"
    
    // Write each student
    FOR i FROM 0 TO stu_count - 1 DO
        WRITE fp, students[i].student_id
        WRITE fp, students[i].name
        WRITE fp, students[i].age
        WRITE fp, students[i].program
        
        // Find matching result
        res_idx = find_result(results, res_count, students[i].student_id)
        IF res_idx >= 0 THEN
            WRITE fp, results[res_idx].total_marks
            WRITE fp, results[res_idx].percentage
            WRITE fp, results[res_idx].grade
            WRITE fp, get_pass_fail(results[res_idx])
        ELSE
            WRITE fp, "N/A,N/A,N/A,N/A"
    
    CLOSE_FILE(fp)
    PRINT "Exported to %s", filename
    
    RETURN 1
END FUNCTION
```

Input Example Output (CSV format):
Student_ID,Name,Age,Program,Total_Marks,Percentage,Grade,Status
1001,John Smith,22,MTech-CS,250,83.33,A,Pass
1002,Jane Doe,21,MTech-AI,180,60.00,B,Pass

Interoperability: CSV can be opened in Excel, Google Sheets, etc.
Complexity: O(n * m)

================================================================================
                    5. MODULE DEPENDENCIES
================================================================================

Dependency Graph:
                    MAIN.C
                       |
                       +---> STUDENT.H
                       |       |
                       |       +---> RESULT.H (for find_result)
                       |
                       +---> RESULT.H
                       |
                       +---> FILE_IO.H
                               |
                               +---> STUDENT.H
                               +---> RESULT.H

Coupling Analysis:
  - Student Module: Depends on no other modules (independent)
  - Result Module: Depends on Student (uses find_result)
  - File I/O Module: Depends on Student and Result
  - Main: Depends on all modules

Cohesion Analysis:
  - Student Module: High cohesion (all student operations)
  - Result Module: High cohesion (all result operations)
  - File I/O Module: High cohesion (all file operations)

================================================================================
               6. QUALITY CHARACTERISTICS IMPLEMENTATION
================================================================================

------------------------------------------------------------------------------
USABILITY (Ease of Use)
------------------------------------------------------------------------------
Implementation:
  - Menu-driven interface with clear options
  - Consistent formatting and display
  - Descriptive error messages with specific issues
  - Validation feedback showing exact problems
  - Clear success/failure messages

Examples:
  ✓ "Error: Student ID must be positive!" (vs generic error)
  ✓ "Note: File not found. Starting with empty database."
  ✓ Formatted tables for data display

------------------------------------------------------------------------------
EFFICIENCY (Optimal Resource Utilization)
------------------------------------------------------------------------------
Memory Efficiency:
  - Static array allocation (no dynamic memory overhead)
  - Fixed-size buffers (no buffer overflow risks)
  - Single copy of data (no duplication)

Time Efficiency:
  - O(n) linear search algorithms
  - O(1) grade calculation
  - Binary file format for fast I/O
  - Single-pass calculations

------------------------------------------------------------------------------
REUSABILITY (Module Reuse)
------------------------------------------------------------------------------
Implementation:
  - Modular design with separate compilation
  - User-defined header files
  - Static library creation (make compile_library)
  - Generic functions without hard-coded values

Usage:
  ✓ Student module can be reused in any student management app
  ✓ Result module can be reused in any grading system
  ✓ File I/O module can be reused for any data persistence

------------------------------------------------------------------------------
INTEROPERABILITY (Data Exchange)
------------------------------------------------------------------------------
Implementation:
  - CSV export for spreadsheet compatibility
  - Binary format for programmatic access
  - get_student_array() and get_result_array() for data access
  - Standard file formats

Platforms:
  ✓ Microsoft Excel
  ✓ Google Sheets
  ✓ LibreOffice Calc
  ✓ Other C applications via header inclusion

================================================================================
                         END OF DOCUMENT
================================================================================

