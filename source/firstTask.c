/*
 * Author: Mirko Galic
 * Purpose: Task for job application.
 * Language:  C
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define LENGTH 100
#define TIMEOUT_TIME 2

int main()
{
    /* buffer - char array used for saving input characters
       input - char array for saving input from console
       position - used for tracking positions in buffer array
    */
	char buffer[LENGTH] = "", input[LENGTH];
	int position = 0;

	do {
		time_t start_time = time(NULL);         /* Measure time between 2 inputs given from console */
		gets(input);
		time_t end_time = time(NULL);

		if (difftime(end_time, start_time) >= TIMEOUT_TIME)  /* If nothing comes for 2 or more seconds call Timeout function */
		{
			Timeout(buffer, &position);
		}

		for (int count = 0; count < strlen(input); count++) /* Send input characters, one by one as parameter in Process function every 100 ms */
		{
			sleep(0.10);
			Process(input[count], buffer, &position);
		}
	} while (1);

	return 0;
}

/*
 * Function:  Process
 * --------------------
 *  called every 100 ms, inserts input character to buffer and check for sequence "GLROX", letters between are allowed
 *
 *  input : character from input
 *  buffer: array of characters received
 *  position: counter of positions in buffer
 *
 *  returns: none
 */

void Process(char *input, char buffer[], int *position)
{
	buffer[*position] = input;  /* Insert character in proper position in buffer, increase position counter */
	*position = *position + 1;

	char *temp;
	temp = strstr(buffer, "G");         /* Find character G in buffer, if found take the rest of array and check for others */
	if (temp != NULL)
	{
		temp = strstr(temp + 1, "L");
		if (temp != NULL)
		{
			temp = strstr(temp + 1, "R");
			if (temp != NULL)
			{
				temp = strstr(temp + 1, "O");
				if (temp != NULL)
				{
					temp = strstr(temp + 1, "X");
					if (temp != NULL)
					{
						Found(buffer, position);        /* If whole sequence is found, call function Found */
					}
					else
					{
						printf("State of buffer is : \"%s\",missing character in the proper order is : \"X\"\n", buffer);   /* If any character is missing print it on console */
					}
				}
				else
				{
					printf("State of buffer is : \"%s\",missing characters in the proper order are : \"O,X\"\n", buffer);
				}
			}
			else
			{
				printf("State of buffer is : \"%s\",missing characters in the proper order are : \"R,O,X\"\n", buffer);
			}
		}
		else
		{
			printf("State of buffer is : \"%s\",missing characters in the proper order are : \"L,R,O,X\"\n", buffer);
		}
	}
	else
	{
		printf("State of buffer is : \"%s\", no matching characters in the proper order\n", buffer);
	}
}

/*
 * Function:  Found
 * --------------------
 *  called when sequence is found, print notification to console, restarts buffer and his position counter
 *
 *  buffer: array of characters received
 *  position: counter of positions in buffer
 *
 *  returns: none
 */

void Found(char buffer[], int *position)
{
	printf("Pattern is found, searching for next\n");
	*position = 0;
	memset(buffer, 0, LENGTH);
}

/*
 * Function:  Timeout
 * --------------------
 *  called when there is no received input for 2 seconds, print notification to console, restarts buffer and his position counter
 *
 *  buffer: array of characters received
 *  position: counter of positions in buffer
 *
 *  returns: none
 */

void Timeout(char buffer[], int *position)
{
	printf("Its been more then %d seconds since last input, restarting buffer\n", TIMEOUT_TIME);
	memset(buffer, 0, *position);
	*position = 0;
}
