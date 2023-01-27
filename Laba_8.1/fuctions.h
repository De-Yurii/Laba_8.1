#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define AMOUNT_OF_STUDENTS 6
#define AMOUNT_OF_GRADES 8
struct int_date {
	int days;
	int months;
	int years;
};
struct student
{
	char surname[100];
	char name[100];
	char birth_date[100];
	int grades[AMOUNT_OF_GRADES];
	float average_grade;
	struct int_date date;
};
float find_average(int grade[AMOUNT_OF_GRADES]);
int std1_std2(struct student student1, struct student student2);
void swap_structures(struct student* Student1, struct student* Student2);
void sort_students(struct student Students[AMOUNT_OF_STUDENTS]);
void seconds(char birth_data[100], struct student* Student);
void make_line();
void input_students(struct student Students[AMOUNT_OF_STUDENTS]);
void output_students(struct student Students[AMOUNT_OF_STUDENTS]);
void find_avarage_grade(struct student Students[AMOUNT_OF_STUDENTS]);
float avrg_stdent_grd(struct student Students[AMOUNT_OF_STUDENTS]);
void prnt_scsful_stdnts(struct student Students[AMOUNT_OF_STUDENTS], float average_grade);

#endif