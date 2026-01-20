#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "result.h"
#include "file_io.h"

static Student students[MAX_STUDENTS];
static int student_count = 0;

static Result results[MAX_STUDENTS];
static int result_count = 0;

void print_main_menu(void);
void print_student_menu(void);
void print_result_menu(void);

void handle_student_operations(void);
void handle_result_operations(void);

void add_new_student(void);
void display_all_students(void);
void search_student_record(void);
void update_student_record(void);
void delete_student_record(void);

void add_result_data(void);
void display_all_results(void);
void calculate_all_grades(void);

void save_data(void);
void load_data(void);
void export_data(void);

int main(void) {
    printf("\n");
    printf("================================================================================\n");
    printf("        STUDENT RESULT PROCESSING SYSTEM v2.0\n");
    printf("        Software Engineering Lab - M.Tech (CS, AI) 2025-26\n");
    printf("================================================================================\n");
    
    load_data();
    
    int choice;
    do {
        print_main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                handle_student_operations();
                break;
            case 2:
                handle_result_operations();
                break;
            case 3:
                save_data();
                break;
            case 4:
                load_data();
                break;
            case 5:
                export_data();
                break;
            case 6:
                printf("\nThank you for using Student Result Processing System!\n");
                printf("Goodbye!\n\n");
                break;
            default:
                printf("\nError: Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void print_main_menu(void) {
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                              MAIN MENU\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  [1] Student Operations\n");
    printf("  [2] Result Operations\n");
    printf("  [3] Save Data to Files\n");
    printf("  [4] Load Data from Files\n");
    printf("  [5] Export to CSV (Interoperability)\n");
    printf("  [6] Exit\n");
    printf("--------------------------------------------------------------------------------\n");
}

void print_student_menu(void) {
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                          STUDENT OPERATIONS\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  [1] Add New Student\n");
    printf("  [2] Display All Students\n");
    printf("  [3] Search Student by ID\n");
    printf("  [4] Update Student Record\n");
    printf("  [5] Delete Student Record\n");
    printf("  [6] Back to Main Menu\n");
    printf("--------------------------------------------------------------------------------\n");
}

void print_result_menu(void) {
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                          RESULT OPERATIONS\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  [1] Add/Update Result\n");
    printf("  [2] Display All Results\n");
    printf("  [3] Calculate Grades\n");
    printf("  [4] Back to Main Menu\n");
    printf("--------------------------------------------------------------------------------\n");
}

void handle_student_operations(void) {
    int choice;
    do {
        print_student_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch (choice) {
            case 1: add_new_student(); break;
            case 2: display_all_students(); break;
            case 3: search_student_record(); break;
            case 4: update_student_record(); break;
            case 5: delete_student_record(); break;
            case 6: printf("\nReturning to main menu...\n"); break;
            default: printf("\nError: Invalid choice!\n");
        }
    } while (choice != 6);
}

void handle_result_operations(void) {
    int choice;
    do {
        print_result_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch (choice) {
            case 1: add_result_data(); break;
            case 2: display_all_results(); break;
            case 3: calculate_all_grades(); break;
            case 4: printf("\nReturning to main menu...\n"); break;
            default: printf("\nError: Invalid choice!\n");
        }
    } while (choice != 4);
}

void add_new_student(void) {
    printf("\n--- Add New Student ---\n");
    
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum students (%d) reached!\n", MAX_STUDENTS);
        return;
    }
    
    Student new_student;
    
    printf("Enter Student ID: ");
    scanf("%d", &new_student.student_id);
    
    printf("Enter Name: ");
    clear_input_buffer();
    fgets(new_student.name, MAX_NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';
    
    printf("Enter Age: ");
    scanf("%d", &new_student.age);
    
    printf("Enter Program (MTech-CS/MTech-AI): ");
    clear_input_buffer();
    fgets(new_student.program, 20, stdin);
    new_student.program[strcspn(new_student.program, "\n")] = '\0';
    
    if (add_student(students, &student_count, new_student)) {
        printf("\nSuccess: Student added successfully!\n");
    } else {
        printf("\nFailed: Could not add student.\n");
    }
}

void display_all_students(void) {
    display_students(students, student_count);
}

void search_student_record(void) {
    int search_id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &search_id);
    
    int index = search_student(students, student_count, search_id);
    
    if (index >= 0) {
        printf("\n--- Student Found ---\n");
        printf("ID: %d\n", students[index].student_id);
        printf("Name: %s\n", students[index].name);
        printf("Age: %d\n", students[index].age);
        printf("Program: %s\n", students[index].program);
    } else {
        printf("\nStudent with ID %d not found.\n", search_id);
    }
}

void update_student_record(void) {
    int update_id;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &update_id);
    
    if (search_student(students, student_count, update_id) < 0) {
        printf("Error: Student with ID %d not found!\n", update_id);
        return;
    }
    
    Student updated_data;
    updated_data.student_id = update_id;
    
    printf("Enter new Name (leave empty to keep current): ");
    clear_input_buffer();
    fgets(updated_data.name, MAX_NAME_LENGTH, stdin);
    updated_data.name[strcspn(updated_data.name, "\n")] = '\0';
    
    printf("Enter new Age (0 to keep current): ");
    scanf("%d", &updated_data.age);
    
    printf("Enter new Program (leave empty to keep current): ");
    clear_input_buffer();
    fgets(updated_data.program, 20, stdin);
    updated_data.program[strcspn(updated_data.program, "\n")] = '\0';
    
    if (update_student(students, student_count, update_id, updated_data)) {
        printf("\nSuccess: Student updated!\n");
    } else {
        printf("\nFailed: Could not update student.\n");
    }
}

void delete_student_record(void) {
    int delete_id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &delete_id);
    
    if (delete_student(students, &student_count, delete_id)) {
        printf("\nSuccess: Student deleted!\n");
        
        int res_idx = find_result(results, result_count, delete_id);
        if (res_idx >= 0) {
            for (int i = res_idx; i < result_count - 1; i++) {
                results[i] = results[i + 1];
            }
            result_count--;
            printf("  -> Associated result also deleted.\n");
        }
    } else {
        printf("\nFailed: Could not delete student.\n");
    }
}

void add_result_data(void) {
    printf("\n--- Add/Update Result ---\n");
    
    int student_id;
    printf("Enter Student ID: ");
    scanf("%d", &student_id);
    
    if (search_student(students, student_count, student_id) < 0) {
        printf("Error: Student with ID %d not found! Add student first.\n", student_id);
        return;
    }
    
    Result new_result;
    new_result.student_id = student_id;
    
    printf("Enter number of courses (max %d): ", MAX_COURSES);
    scanf("%d", &new_result.num_courses);
    if (new_result.num_courses > MAX_COURSES) {
        new_result.num_courses = MAX_COURSES;
    }
    
    for (int i = 0; i < new_result.num_courses; i++) {
        printf("\nCourse %d:\n", i + 1);
        printf("  Course ID: ");
        scanf("%d", &new_result.courses[i].course_id);
        printf("  Course Name: ");
        clear_input_buffer();
        fgets(new_result.courses[i].course_name, 30, stdin);
        new_result.courses[i].course_name[strcspn(new_result.courses[i].course_name, "\n")] = '\0';
        printf("  Max Marks: ");
        scanf("%d", &new_result.courses[i].max_marks);
        printf("  Marks Obtained: ");
        scanf("%d", &new_result.courses[i].marks_obtained);
    }
    
    int existing_idx = find_result(results, result_count, student_id);
    if (existing_idx >= 0) {
        results[existing_idx] = new_result;
        calculate_result(&results[existing_idx]);
        printf("\nSuccess: Result updated!\n");
    } else {
        if (add_result(results, &result_count, new_result)) {
            printf("\nSuccess: Result added!\n");
        } else {
            printf("\nFailed: Could not add result.\n");
        }
    }
}

void display_all_results(void) {
    display_results(results, result_count);
}

void calculate_all_grades(void) {
    if (result_count == 0) {
        printf("\nNo results to process!\n");
        return;
    }
    
    printf("\nRecalculating grades for all students...\n");
    for (int i = 0; i < result_count; i++) {
        calculate_result(&results[i]);
    }
    printf("Success: All grades recalculated!\n");
    display_all_results();
}

void save_data(void) {
    printf("\n--- Save Data ---\n");
    if (save_students_to_file(students, student_count, STUDENT_DATA_FILE)) {
        save_results_to_file(results, result_count, RESULT_DATA_FILE);
    }
}

void load_data(void) {
    printf("\n--- Load Data ---\n");
    load_students_from_file(students, &student_count, STUDENT_DATA_FILE);
    load_results_from_file(results, &result_count, RESULT_DATA_FILE);
}

void export_data(void) {
    printf("\n--- Export to CSV ---\n");
    export_to_csv(students, student_count, results, result_count, "student_results.csv");
}

