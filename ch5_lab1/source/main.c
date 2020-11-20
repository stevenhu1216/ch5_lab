#include<stdio.h>
#include<stdlib.h>

#define students 3
#define exams 4

void minimum(int grades[][exams], int pupils, int tests);
void maximum(int grades[][exams], int pupils, int tests);
void average(int grades[][exams], int pupils, int tests);
void printarray(int grades[][exams], int pupils, int tests);
void printmenu();

int main() {

	//initial std grades
	int studentgrades[students][exams] = { {77,68,86,73},
										   {96,87,89,78},
										   {70,90,86,81} };

	void(*processgrages[4])(int[students][exams], int, int)
		= { printarray ,minimum ,maximum ,average };


	int choice = 0;

	while (choice != 4) {
		do {
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4) {
			(*processgrages[choice])(studentgrades, students, exams);
		}
		else {
			printf("\tprogram ended. \n");
		}
	}

	system("pause");
	return 0;
}

void minimum(int grades[][exams], int pupils, int tests) {

	int i, j;
	int lowgrade = 100;

	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\tthe lowest grade is %d", lowgrade);
	printf("\n");
}

void maximum(int grades[][exams], int pupils, int tests) {
	int i, j;
	int highgrade = 0;

	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grades[i][j] > highgrade)
				highgrade = grades[i][j];
		}
	}
	printf("\n\tthe highest grade is %d", highgrade);
	printf("\n");
}

void average(int grades[][exams], int pupils, int tests) {

	int i, j, total;
	for (i = 0; i < pupils; i++) {
		total = 0;
		for (j = 0; j < tests; j++) {

			total += grades[i][j];

		}
		printf("\n\tthe average grade for student %d is %.1f"
			, i + 1, (double)total / tests);
	}
	printf("\n");
}

void printarray(int grades[][exams], int pupils, int tests) {

	int i, j;

	printf("\n\t\t\t[0]    [1]    [2]    [3]");
	for (i = 0; i < pupils; i++) {
		printf("\n\tstudentgrades[%d]", i);
		for (j = 0; j < tests; j++) {
			//允許輸入七個數值，-號代表靠左對齊
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu() {
	printf("\n");
	printf("\tenter a choice:\n");
	printf("\t0 print the array of grades\n");
	printf("\t1 find the minimum grade\n");
	printf("\t2 find the minimum grade\n");
	printf("\t3 print the avarage on all tests for each student\n");
	printf("\t4 end program\n");
	printf("choice:");
}