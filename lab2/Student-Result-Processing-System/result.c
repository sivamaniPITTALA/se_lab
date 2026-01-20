#include "result.h"

static Result g_results[MAX_STUDENTS];
static int g_result_count = 0;

Result* get_result_array(void) {
    return g_results;
}

int get_result_count(void) {
    return g_result_count;
}

const char* calculate_grade(float percentage) {
    if (percentage >= GRADE_A_PLUS) return "A+";
    else if (percentage >= GRADE_A) return "A";
    else if (percentage >= GRADE_B_PLUS) return "B+";
    else if (percentage >= GRADE_B) return "B";
    else if (percentage >= GRADE_C) return "C";
    else return "F";
}

const char* get_grade_letter(float percentage) {
    return calculate_grade(percentage);
}

const char* get_pass_fail(Result r) {
    return (r.percentage >= GRADE_C) ? "Pass" : "Fail";
}

int add_result(Result results[], int *count, Result new_result) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Maximum result limit reached!\n");
        return 0;
    }
    
    for (int i = 0; i < *count; i++) {
        if (results[i].student_id == new_result.student_id) {
            printf("Error: Result for student ID %d already exists!\n", new_result.student_id);
            return 0;
        }
    }
    
    calculate_result(&new_result);
    
    results[*count] = new_result;
    (*count)++;
    
    g_results[*count - 1] = new_result;
    g_result_count = *count;
    
    return 1;
}

void calculate_result(Result *result) {
    int total_max = 0;
    int total_obtained = 0;
    
    for (int i = 0; i < result->num_courses; i++) {
        total_max += result->courses[i].max_marks;
        total_obtained += result->courses[i].marks_obtained;
    }
    
    result->total_marks = total_obtained;
    
    if (total_max > 0) {
        result->percentage = ((float)total_obtained / total_max) * 100;
    } else {
        result->percentage = 0;
    }
    
    strncpy(result->grade, calculate_grade(result->percentage), 4);
}

void display_results(Result results[], int count) {
    printf("\n");
    printf("================================================================================\n");
    printf("                           STUDENT RESULTS (%d records)\n", count);
    printf("================================================================================\n");
    printf("%-8s %-12s %-12s %-10s %-8s %-8s\n", 
           "ID", "Total Marks", "Percentage", "Grade", "Status", "Courses");
    printf("--------------------------------------------------------------------------------\n");
    
    if (count == 0) {
        printf("No results to display!\n");
        printf("================================================================================\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%-8d %-12.0f %-12.2f %-10s %-8s %-d\n",
               results[i].student_id,
               results[i].total_marks,
               results[i].percentage,
               results[i].grade,
               get_pass_fail(results[i]),
               results[i].num_courses);
    }
    printf("================================================================================\n");
    
    printf("\nCourse-wise Details:\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent ID %d:\n", results[i].student_id);
        for (int j = 0; j < results[i].num_courses; j++) {
            printf("  %s (%d): %d/%d\n",
                   results[i].courses[j].course_name,
                   results[i].courses[j].course_id,
                   results[i].courses[j].marks_obtained,
                   results[i].courses[j].max_marks);
        }
    }
}

int find_result(Result results[], int count, int student_id) {
    for (int i = 0; i < count; i++) {
        if (results[i].student_id == student_id) {
            return i;
        }
    }
    return -1;
}

