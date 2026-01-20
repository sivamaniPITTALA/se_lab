#ifndef RESULT_H
#define RESULT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STUDENTS 100
#define GRADE_A_PLUS 90
#define GRADE_A 80
#define GRADE_B_PLUS 70
#define GRADE_B 60
#define GRADE_C 50
#define GRADE_F 0

typedef struct {
    int course_id;
    char course_name[30];
    int max_marks;
    int marks_obtained;
    int credits;
} Course;

typedef struct {
    int student_id;
    Course courses[MAX_COURSES];
    int num_courses;
    float total_marks;
    float percentage;
    char grade[5];
} Result;

const char* calculate_grade(float percentage);
int add_result(Result results[], int *count, Result new_result);
void display_results(Result results[], int count);
void calculate_result(Result *result);
int find_result(Result results[], int count, int student_id);
const char* get_grade_letter(float percentage);
const char* get_pass_fail(Result r);

#endif

