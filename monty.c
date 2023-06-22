#include "monty.h"

char *user = "stack";

/**
 * main - Entry function into the  monty program
 * @argc: Argument count.
 * @argv: Argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int zip;
	int fp;
	unsigned int line_number;
	ssize_t inter;
	char *line;
	size_t length;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = open(argv[1], O_RDONLY);
	if (fp == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	do {
		line_number++;
		line = NULL;
		length = 0;
		inter = m_getline(&line, &length, fp);
		if (inter > 2)
		{
			zip = m_inst(&stack, line, line_number);
			if (zip == -1)
				inter = -2;
		}
		else
			free(line);
	} while (inter >= 0);

	close(fp);
	free_stack(stack);
	if (inter == -1)
		return (0);
	exit(EXIT_FAILURE);
}
