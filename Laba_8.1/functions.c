#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "fuctions.h"

float find_average(int grade[AMOUNT_OF_GRADES]) {
	float average = 0;
	for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
		average += grade[i];
	}
	average /= AMOUNT_OF_GRADES;
	return average;
}

int std1_std2(struct student student1, struct student student2) {
	if (student1.date.years < student2.date.years) {
		return 0;
	}
	else if (student1.date.years > student2.date.years) {
		return 1;
	}
	if (student1.date.months < student2.date.months) {
		return 0;
	}
	else if (student1.date.months > student2.date.months) {
		return 1;
	}
	if (student1.date.days < student2.date.days) {
		return 0;
	}
	else if (student1.date.days > student2.date.days) {
		return 1;
	}
	return 0;
}

void swap_structures(struct student* Student1, struct student* Student2) {
	struct student temp;
	temp = *Student1;
	*Student1 = *Student2;
	*Student2 = temp;
}

void sort_students(struct student Students[AMOUNT_OF_STUDENTS]) {
	for (int i = 0; i < AMOUNT_OF_STUDENTS - 1; i++) {
		for (int j = 0; j < AMOUNT_OF_STUDENTS - i - 1; j++) {
			if (std1_std2(Students[j], Students[j + 1])) {
				swap_structures(&Students[j], &(Students[j + 1]));
			}
		}
	}
}

void seconds(char birth_data[100], struct student* Student) {
	char temp[100];
	for (int i = 0; i < 100; i++) {
		temp[i] = birth_data[i];
	}
	char* ptr = strtok(temp, ".");
	int amount;
	amount = atoi(ptr);
	(*Student).date.days = amount;
	ptr = strtok(NULL, ".");
	amount = atoi(ptr);
	(*Student).date.months = amount;
	ptr = strtok(NULL, ".");
	amount = atoi(ptr);
	(*Student).date.years = amount;
}

void make_line() {
	for (int i = 0; i < 66; i++) {
		printf("=");
	}
	printf("\n");
}

void input_students(struct student Students[AMOUNT_OF_STUDENTS]) {
	FILE* file = fopen("Students.txt", "r");
	char* ptr; char data[100];
	int current_student = 0;
	char limits[] = " ";
	while (!feof(file)) {
		fgets(data, 1000, file);
		ptr = strtok(data, limits);
		strcpy(Students[current_student].surname, ptr);

		ptr = strtok(NULL, limits);
		strcpy(Students[current_student].name, ptr);

		ptr = strtok(NULL, limits);
		strcpy(Students[current_student].birth_date, ptr);

		ptr = strtok(NULL, limits);
		int j = 0;
		for (int i = 0; *ptr != '}'; i++) {
			if (isdigit(*ptr)) {
				Students[current_student].grades[j] = atoi(ptr);
				j++;
			}
			ptr++;
		}
		current_student++;
	}
}
void output_students(struct student Students[AMOUNT_OF_STUDENTS]) {
	printf("| Name:\t\t| Surname:\t| Birth date: \t| Average grade: |\n");
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		make_line();
		printf("| %-10s\t| %-10s\t| %s\t| %f\t |\n", Students[i].name, Students[i].surname, Students[i].birth_date, Students[i].average_grade);
	}
	make_line();
}
void find_avarage_grade(struct student Students[AMOUNT_OF_STUDENTS]) {
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		Students[i].average_grade = find_average(Students[i].grades);
	}
}

float avrg_stdent_grd(struct student Students[AMOUNT_OF_STUDENTS]) {
	float suma = 0;
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		suma += Students[i].average_grade;
	}
	suma /= AMOUNT_OF_STUDENTS;
	return suma;
}

void prnt_scsful_stdnts(struct student Students[AMOUNT_OF_STUDENTS], float average_grade) {
	printf("| Name:\t\t| Surname:\t| Birth date: \t| Average grade: |\n");
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		if (Students[i].average_grade > average_grade) {
			make_line();
			printf("| %-10s\t| %-10s\t| %s\t| %f\t |\n", Students[i].name, Students[i].surname, Students[i].birth_date, Students[i].average_grade);
		}
	}
	make_line();
}
