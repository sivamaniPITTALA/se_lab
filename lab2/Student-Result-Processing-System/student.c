#include "student.h"

static Student g_students[MAX_STUDENTS];
static int g_student_count = 0;

Student* get_student_array(void) {
    return g_students;
}

int get_student_count(void) {
    return g_student_count;
}

int add_student(Student students[], int *count, Student new_student) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Maximum student limit reached!\n");
        return 0;
    }
    
    if (!validate_student_data(new_student)) {
        printf("Error: Invalid student data!\n");
        return 0;
    }
    
    for (int i = 0; i < *count; i++) {
        if (students[i].student_id == new_student.student_id) {
            printf("Error: Student with ID %d already exists!\n", new_student.student_id);
            return 0;
        }
    }
    
    students[*count] = new_student;
    (*count)++;
    
    g_students[*count - 1] = new_student;
    g_student_count = *count;
    
    return 1;
}

void display_students(Student students[], int count) {
    printf("\n");
    printf("================================================================================\n");
    printf("                           STUDENT LIST (%d students)\n", count);
    printf("================================================================================\n");
    printf("%-10s %-25s %-5s %-15s\n", "ID", "Name", "Age", "Program");
    printf("--------------------------------------------------------------------------------\n");
    
    if (count == 0) {
        printf("No students to display!\n");
        printf("================================================================================\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-5d %-15s\n", 
               students[i].student_id, 
               students[i].name, 
               students[i].age, 
               students[i].program);
    }
    printf("================================================================================\n");
}

int search_student(Student students[], int count, int student_id) {
    for (int i = 0; i < count; i++) {
        if (students[i].student_id == student_id) {
            return i;
        }
    }
    return -1;
}

int update_student(Student students[], int count, int student_id, Student updated_data) {
    int index = search_student(students, count, student_id);
    if (index == -1) {
        printf("Error: Student with ID %d not found!\n", student_id);
        return 0;
    }
    
    if (!validate_student_data(updated_data)) {
        printf("Error: Invalid student data for update!\n");
        return 0;
    }
    
    students[index].age = updated_data.age;
    strncpy(students[index].name, updated_data.name, MAX_NAME_LENGTH - 1);
    students[index].name[MAX_NAME_LENGTH - 1] = '\0';
    strncpy(students[index].program, updated_data.program, 19);
    students[index].program[19] = '\0';
    
    return 1;
}

int delete_student(Student students[], int *count, int student_id) {
    int index = search_student(students, *count, student_id);
    if (index == -1) {
        printf("Error: Student with ID %d not found!\n", student_id);
        return 0;
    }
    
    for (int i = index; i < (*count - 1); i++) {
        students[i] = students[i + 1];
    }
    
    (*count)--;
    g_student_count = *count;
    
    return 1;
}

int validate_student_data(Student s) {
    if (s.student_id <= 0) {
        printf("  -> Error: Student ID must be positive!\n");
        return 0;
    }
    if (strlen(s.name) == 0) {
        printf("  -> Error: Name cannot be empty!\n");
        return 0;
    }
    if (s.age < 15 || s.age > 50) {
        printf("  -> Error: Age must be between 15 and 50!\n");
        return 0;
    }
    if (strlen(s.program) == 0) {
        printf("  -> Error: Program cannot be empty!\n");
        return 0;
    }
    return 1;
}

