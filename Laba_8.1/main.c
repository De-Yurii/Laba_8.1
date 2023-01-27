#include <stdio.h>
#include "fuctions.h"
int main() {
	float average_grade;
	struct student Students[AMOUNT_OF_STUDENTS];
	input_students(Students);
	find_avarage_grade(Students);
	for (int i = 0; i < AMOUNT_OF_STUDENTS; i++) {
		seconds(Students[i].birth_date, &Students[i]);
	}
	printf("Student's without sorting: \n");
	output_students(Students);
	sort_students(Students);
	printf("Student's with sorting: \n");
	output_students(Students);
	average_grade = avrg_stdent_grd(Students);
	printf("%f\n", average_grade);
	printf("The best students: \n");
	prnt_scsful_stdnts(Students, average_grade);
}