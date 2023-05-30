#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factors - Prints the prime factors of numbers from a file.
 * @filename: The name of the file containing numbers.
 *
 * Description: This function reads numbers from
 * a file and prints their prime factors.
 * It opens the file, reads each line,
 * converts the line to an integer, and finds the
 * prime factors of the number.
 * The prime factors are printed in the format "number=i*j",
 * where i and j are the prime factors of the number.
 */
void factors(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Cannot open file %s\n", filename);
		return;
	}

	char line[100];

	while (fgets(line, sizeof(line), file) != NULL)

	{
		int n = atoi(line);

		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				printf("%d=%d*%d\n", n, i, n / i);
				break;
			}
		}
	}

	fclose(file);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Description: This function serves as the entry
 * point of the program. It checks
 * if the correct number of command-line arguments is provided, and if not, it
 * displays the correct usage.
 * It then calls the factors function with the file name
 * provided as the command-line argument.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	factors(argv[1]);

	return (0);
}
