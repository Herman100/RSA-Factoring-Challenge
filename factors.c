#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Description: This program takes a filename as a command-line argument and
 * reads each line of the file. For each line, it finds the factors of the
 * number and prints them in the format "n=i*j" where n is the number and i, j
 * are the factors.
 *
 * Return: 0 on success, 1 on error.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: could not open file %s\n", argv[1]);
		return (1);
	}

	char line[1024];

	while (fgets(line, sizeof(line), file))
	{
		long n = atol(line);

		for (long i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				printf("%ld=%ld*%ld\n", n, i, n / i);
				break;
			}
		}
	}

	fclose(file);
	return (0);
}
