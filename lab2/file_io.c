#include "file_io.h"

int save_students_to_file(Student students[], int count, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Cannot open file %s for writing!\n", filename);
        return 0;
    }
    
    if (fwrite(&count, sizeof(int), 1, fp) != 1) {
        printf("Error: Failed to write student count!\n");
        fclose(fp);
        return 0;
    }
    
    if (fwrite(students, sizeof(Student), count, fp) != (size_t)count) {
        printf("Error: Failed to write all students!\n");
        fclose(fp);
        return 0;
    }
    
    fclose(fp);
    printf("Successfully saved %d students to %s\n", count, filename);
    return 1;
}

int load_students_from_file(Student students[], int *count, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Note: File %s not found. Starting with empty database.\n", filename);
        *count = 0;
        return 0;
    }
    
    if (fread(count, sizeof(int), 1, fp) != 1) {
        printf("Error: Failed to read student count!\n");
        fclose(fp);
        *count = 0;
        return 0;
    }
    
    if (fread(students, sizeof(Student), *count, fp) != (size_t)*count) {
        printf("Error: Failed to read all students!\n");
        fclose(fp);
        *count = 0;
        return 0;
    }
    
    fclose(fp);
    printf("Successfully loaded %d students from %s\n", *count, filename);
    return 1;
}

int save_results_to_file(Result results[], int count, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Cannot open file %s for writing!\n", filename);
        return 0;
    }
    
    if (fwrite(&count, sizeof(int), 1, fp) != 1) {
        printf("Error: Failed to write result count!\n");
        fclose(fp);
        return 0;
    }
    
    if (fwrite(results, sizeof(Result), count, fp) != (size_t)count) {
        printf("Error: Failed to write all results!\n");
        fclose(fp);
        return 0;
    }
    
    fclose(fp);
    printf("Successfully saved %d results to %s\n", count, filename);
    return 1;
}

int load_results_from_file(Result results[], int *count, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Note: File %s not found. Starting with empty results.\n", filename);
        *count = 0;
        return 0;
    }
    
    if (fread(count, sizeof(int), 1, fp) != 1) {
        printf("Error: Failed to read result count!\n");
        fclose(fp);
        *count = 0;
        return 0;
    }
    
    if (fread(results, sizeof(Result), *count, fp) != (size_t)*count) {
        printf("Error: Failed to read all results!\n");
        fclose(fp);
        *count = 0;
        return 0;
    }
    
    fclose(fp);
    printf("Successfully loaded %d results from %s\n", *count, filename);
    return 1;
}

int export_to_csv(Student students[], int stu_count, Result results[], int res_count, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Cannot create CSV file %s!\n", filename);
        return 0;
    }
    
    fprintf(fp, "Student_ID,Name,Age,Program,Total_Marks,Percentage,Grade,Status\n");
    
    for (int i = 0; i < stu_count; i++) {
        fprintf(fp, "%d,%s,%d,%s,",
                students[i].student_id,
                students[i].name,
                students[i].age,
                students[i].program);
        
        int res_idx = find_result(results, res_count, students[i].student_id);
        if (res_idx >= 0) {
            fprintf(fp, "%.0f,%.2f,%s,%s\n",
                    results[res_idx].total_marks,
                    results[res_idx].percentage,
                    results[res_idx].grade,
                    get_pass_fail(results[res_idx]));
        } else {
            fprintf(fp, "N/A,N/A,N/A,N/A\n");
        }
    }
    
    fclose(fp);
    printf("Successfully exported data to %s (CSV format)\n", filename);
    printf("  -> Can be opened in Excel, Google Sheets, etc.\n");
    return 1;
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

