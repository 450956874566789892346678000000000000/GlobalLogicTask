/*
 * Author: Mirko Galic
 * Purpose: Task for job application.
 * Language:  C
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_RANGE_LIMIT 100
#define LOWER_RANGE_LIMIT 0
#define ITERATIONS 100

int main()
{
	int randomNumber;
	srand(time(0));
	printf("INPUT   OUTPUT\n");
	for (int count = 0; count < ITERATIONS; count++)
	{
		randomNumber = (rand() % (UPPER_RANGE_LIMIT - LOWER_RANGE_LIMIT + 1)) + LOWER_RANGE_LIMIT; /* Random number pretending to be input */

		printf("%d      ", randomNumber);
		if (randomNumber % 15 == 0)
		{
			printf("GlobalLogic\n");
		}
		else if (randomNumber % 3 == 0)
		{
			printf("Global\n");
		}
		else if (randomNumber % 5 == 0)
		{
			printf("Logic\n");
		}
		else
		{
			printf("%d\n");
		}
	}

	return 0;
}
