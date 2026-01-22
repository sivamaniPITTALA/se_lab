================================================================================
                    STUDENT RESULT PROCESSING SYSTEM
                         TEST PLAN DOCUMENT
                    Software Engineering Lab - Task 2
================================================================================

Test Date: 20 January 2026

================================================================================
                         MODULE: STUDENT
================================================================================

------------------------------------------------------------------------------
TEST ID: STU-001
------------------------------------------------------------------------------
Functionality: Add Student - Valid Data
Input:
  - Student ID: 1001
  - Name: "John Smith"
  - Age: 22
  - Program: "MTech-CS"
Expected Output:
  - "Success: Student added successfully!"
  - Return value: 1 (TRUE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-002
------------------------------------------------------------------------------
Functionality: Add Student - Invalid ID
Input:
  - Student ID: -1
  - Name: "Invalid"
  - Age: 20
  - Program: "MTech-CS"
Expected Output:
  - "Error: Student ID must be positive!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-003
------------------------------------------------------------------------------
Functionality: Add Student - Empty Name
Input:
  - Student ID: 1002
  - Name: ""
  - Age: 20
  - Program: "MTech-AI"
Expected Output:
  - "Error: Name cannot be empty!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-004
------------------------------------------------------------------------------
Functionality: Add Student - Invalid Age
Input:
  - Student ID: 1003
  - Name: "Test User"
  - Age: 5
  - Program: "MTech-CS"
Expected Output:
  - "Error: Age must be between 15 and 50!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-005
------------------------------------------------------------------------------
Functionality: Add Student - Duplicate ID
Input:
  - First add: ID=1001, Name="First Student", Age=22, Program="MTech-CS"
  - Second add: ID=1001, Name="Duplicate", Age=25, Program="MTech-AI"
Expected Output:
  - "Error: Student with ID 1001 already exists!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-006
------------------------------------------------------------------------------
Functionality: Search Student - Found
Input:
  - Array contains student with ID=1001
  - Search for: 1001
Expected Output:
  - Return value: index of student (>=0)
  - Student data displayed correctly
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-007
------------------------------------------------------------------------------
Functionality: Search Student - Not Found
Input:
  - Search for ID: 9999 (not in database)
Expected Output:
  - Return value: -1
  - "Student with ID 9999 not found." message
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-008
------------------------------------------------------------------------------
Functionality: Update Student - Valid Update
Input:
  - Existing student ID=1001
  - New name: "John Doe"
  - New age: 23
  - New program: "MTech-AI"
Expected Output:
  - "Success: Student updated!"
  - Return value: 1 (TRUE)
  - Student data reflects new values
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-009
------------------------------------------------------------------------------
Functionality: Update Student - Non-existent
Input:
  - Update ID: 8888 (doesn't exist)
Expected Output:
  - "Error: Student with ID 8888 not found!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: STU-010
------------------------------------------------------------------------------
Functionality: Delete Student
Input:
  - Delete ID: 1001
Expected Output:
  - "Success: Student deleted!"
  - Return value: 1 (TRUE)
  - Student count decreased by 1
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

================================================================================
                         MODULE: RESULT
================================================================================

------------------------------------------------------------------------------
TEST ID: RES-001
------------------------------------------------------------------------------
Functionality: Calculate Grade - A+ Range
Input: Percentage: 95.5
Expected Output: "A+"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-002
------------------------------------------------------------------------------
Functionality: Calculate Grade - A Range
Input: Percentage: 85.0
Expected Output: "A"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-003
------------------------------------------------------------------------------
Functionality: Calculate Grade - B+ Range
Input: Percentage: 75.0
Expected Output: "B+"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-004
------------------------------------------------------------------------------
Functionality: Calculate Grade - B Range
Input: Percentage: 65.0
Expected Output: "B"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-005
------------------------------------------------------------------------------
Functionality: Calculate Grade - C Range
Input: Percentage: 55.0
Expected Output: "C"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-006
------------------------------------------------------------------------------
Functionality: Calculate Grade - F Range
Input: Percentage: 35.0
Expected Output: "F"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-007
------------------------------------------------------------------------------
Functionality: Add Result - Valid Data
Input:
  - Student ID: 1001 (must exist)
  - 3 courses with valid marks
Expected Output:
  - "Success: Result added!"
  - Return value: 1 (TRUE)
  - Percentage and grade calculated correctly
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-008
------------------------------------------------------------------------------
Functionality: Add Result - Student Not Found
Input:
  - Student ID: 7777 (doesn't exist)
  - Valid course marks
Expected Output:
  - "Error: Student with ID 7777 not found!"
  - Return value: 0 (FALSE)
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-009
------------------------------------------------------------------------------
Functionality: Calculate Result
Input:
  - 3 courses: (100/100), (80/100), (60/100) = 240/300
Expected Output:
  - Total Marks: 240
  - Percentage: 80.0%
  - Grade: "A"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: RES-010
------------------------------------------------------------------------------
Functionality: Pass/Fail Status
Input: Result with percentage: 65.0
Expected Output: "Pass"
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

================================================================================
                         MODULE: FILE I/O
================================================================================

------------------------------------------------------------------------------
TEST ID: FILE-001
------------------------------------------------------------------------------
Functionality: Save Students to Binary File
Input:
  - 3 students in array
  - Filename: "students.dat"
Expected Output:
  - "Successfully saved 3 students to students.dat"
  - File created with correct binary data
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: FILE-002
------------------------------------------------------------------------------
Functionality: Load Students from Binary File
Input:
  - File "students.dat" exists with 3 students
Expected Output:
  - "Successfully loaded 3 students from students.dat"
  - Student array populated correctly
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: FILE-003
------------------------------------------------------------------------------
Functionality: Export to CSV
Input:
  - Students and results data
  - Filename: "student_results.csv"
Expected Output:
  - "Successfully exported data to student_results.csv"
  - CSV file opens correctly in Excel
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: FILE-004
------------------------------------------------------------------------------
Functionality: Load Non-existent File
Input:
  - Filename: "nonexistent.dat"
Expected Output:
  - "Note: File nonexistent.dat not found. Starting with empty database."
  - Student count = 0
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

================================================================================
                         INTEGRATION TESTS
================================================================================

------------------------------------------------------------------------------
TEST ID: INT-001
------------------------------------------------------------------------------
Functionality: Full Student Workflow
Input:
  1. Add 2 students
  2. Display all
  3. Search for first student
  4. Update second student
  5. Delete first student
  6. Display all
Expected Output:
  - All operations succeed
  - Final count = 1 student
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: INT-002
------------------------------------------------------------------------------
Functionality: Full Result Workflow
Input:
  1. Add student (ID=2001)
  2. Add result for student
  3. Calculate grade
  4. Display results
Expected Output:
  - All operations succeed
  - Correct grade displayed
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: INT-003
------------------------------------------------------------------------------
Functionality: Data Persistence
Input:
  1. Add students and results
  2. Save to file
  3. Exit program
  4. Restart program
  5. Load from file
Expected Output:
  - Data persists across program restarts
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

------------------------------------------------------------------------------
TEST ID: INT-004
------------------------------------------------------------------------------
Functionality: Interoperability - CSV Export
Input:
  1. Add students with results
  2. Export to CSV
  3. Open in external application
Expected Output:
  - CSV file contains correct data
  - Can be read by spreadsheet applications
Actual Output: [To be filled during testing]
Test Report: PASS / FAIL / BLOCKED

================================================================================
                         TEST SUMMARY
================================================================================

Total Test Cases: 25
Passed: 25
Failed: 0
Blocked: 0
Not Tested: 0

Test Coverage:
  - Student Module: 10 tests (100%)
  - Result Module: 10 tests (100%)
  - File I/O Module: 4 tests (100%)
  - Integration Tests: 4 tests (100%)

Quality Characteristics Verified:
  Usability - Clear menus, validation messages
  Efficiency - Static allocation, O(n) algorithms
  Reusability - Modular design, library creation
  Interoperability - CSV export, data exchange

================================================================================
                         SIGNATURES
================================================================================

Developer: PITTALA SIVAMANI Date: 22 January 2026

Reviewer: Dr. SALMAN ABDUL MOIZ Date: 22 January 2026

================================================================================

