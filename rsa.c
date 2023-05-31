#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * is_prime - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: True if the number is prime, false otherwise.
 */

bool is_prime(long n)
{
	if (n <= 1)
		return (false);
	if (n <= 3)
		return (true);
	if (n % 2 == 0 || n % 3 == 0)
		return (false);
	for (long i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return (false);
	return (true);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
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
			if (n % i == 0 && is_prime(i) && is_prime(n / i))
			{
				printf("%ld=%ld*%ld\n", n, i, n / i);
				break;
			}
		}
	}

	fclose(file);
	return (0);
}
