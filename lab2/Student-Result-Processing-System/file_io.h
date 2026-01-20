#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include "student.h"
#include "result.h"

#define STUDENT_DATA_FILE "students.dat"
#define RESULT_DATA_FILE "results.dat"

int save_students_to_file(Student students[], int count, const char *filename);
int load_students_from_file(Student students[], int *count, const char *filename);
int save_results_to_file(Result results[], int count, const char *filename);
int load_results_from_file(Result results[], int *count, const char *filename);
int export_to_csv(Student students[], int stu_count, Result results[], int res_count, const char *filename);
void clear_input_buffer(void);

#endif

