#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define MAX_COURSES 5

typedef struct {
    int student_id;
    char name[MAX_NAME_LENGTH];
    int age;
    char program[20];
} Student;

int add_student(Student students[], int *count, Student new_student);
void display_students(Student students[], int count);
int search_student(Student students[], int count, int student_id);
int update_student(Student students[], int count, int student_id, Student updated_data);
int delete_student(Student students[], int *count, int student_id);
int validate_student_data(Student s);

#endif

