#include<stdio.h>
#include<stdlib.h>

#define issues 5
#define ratings 10

void recordresponse(int issue, int rating);
void highestratings();
void lowestratings();
float averagerating(int issue);
void displayresults();

int responses[issues][ratings];
const char *topics[issues] = { "global warming","the economy",
							"war","health care","education" };

int main() {
	int response, i;
	do
	{
		printf("please rate the following topics on a scale from 1-10"
			"\n 1=least important,10=most important\n");

		for (i = 0; i < issues; i++) {

			do {
				printf("%s? ", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}

		printf("enter 1 to stop. enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response != 1);

	displayresults();
	system("pause");
	return 0;
}
void recordresponse(int issue, int rating) {
	responses[issue][rating - 1]++;
}

void highestratings() {

	int highrating = 0;
	int hightopic = 0;
	int i, j;

	for (i = 0; i < issues; i++) {
		int topicrating = 0;
		for (j = 0; j < ratings; j++) {
			topicrating += responses[i][j] * (j + 1);
		}

		if (highrating < topicrating) {
			highrating = topicrating;
			hightopic = i;
		}
	}

	printf("the highest rated topic was");
	printf("%s",topics[hightopic]);
	printf("with a total rating of %d\n", highrating);
}

void lowestratings() {
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;

	for (i = 0; i < issues; i++) {
		int topicrating = 0;

		for (j = 0; j < ratings; j++) {
			topicrating += responses[i][j] * (j + 1);
		}

		if (i == 0) {
			lowrating = topicrating;
		}
		if (lowrating > topicrating) {
			lowrating = topicrating;
			lowrating = i;
		}
	}

	printf("the lowest rated topic was");
	printf("%s",topics[lowrating]);
	printf("with a total rating of %d\n",lowrating);
}

float averagerating(int issue) {
	float total = 0;
	int counter = 0;
	int i;

	for (i = 0; i < ratings; i++) {

		if (responses[issue][i] != 0) {
			total += responses[issue][i] * (i + 1);
			counter += responses[issue][i];
		}
	}
	return total / counter;
}

void displayresults() {

	int i, j;
	printf("%20s", "topic");

	for (i = 1; i <= ratings; i++) {
		printf("%4d", i);
	}
	printf("%20s", "average rating");
	printf("\n");

	for (i = 0; i < issues; i++) {

		printf("%20s", topics[i]);

		for (j = 0; j < ratings; j++) {
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n", averagerating(i));
	}
	highestratings();
	lowestratings();
}