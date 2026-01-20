CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -D_POSIX_C_SOURCE=200809L
LDFLAGS = -lm

TARGET = student_result_system

SRCS = main.c student.c result.c file_io.c
OBJS = $(SRCS:.c=.o)
HEADERS = student.h result.h file_io.h
LIBNAME = resultlib.a

.PHONY: all clean run compile_library test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build complete! Run with: ./$(TARGET)"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

compile_library: $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)
	@echo "Library $(LIBNAME) created!"

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(LIBNAME) *.dat *.csv
	@echo "Cleaned all build files!"

info:
	@echo "=== Student Result Processing System Modules ==="
	@echo ""
	@echo "Module: Student Management"
	@echo "  Files: student.h, student.c"
	@echo "  Functions: add_student, display_students, search_student, update_student, delete_student"
	@echo ""
	@echo "Module: Result Processing"
	@echo "  Files: result.h, result.c"
	@echo "  Functions: calculate_grade, add_result, display_results, calculate_result"
	@echo ""
	@echo "Module: File I/O"
	@echo "  Files: file_io.h, file_io.c"
	@echo "  Functions: save_students_to_file, load_students_from_file, export_to_csv"

debug: CFLAGS += -g -O0
debug: clean $(TARGET)
	@echo "Debug build complete!"

help:
	@echo "Available targets:"
	@echo "  make all             - Compile the entire system"
	@echo "  make run             - Compile and run the system"
	@echo "  make compile_library - Create static library"
	@echo "  make clean           - Remove build artifacts"
	@echo "  make info            - Display module information"
	@echo "  make help            - Show this help message"

