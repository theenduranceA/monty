#include "monty.h"

/**
 * m_pchar - Function that peek char at the top of the stack
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_pchar(stack_t **stack, unsigned int line_number)
{
	int x;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	if (x < 0 || x > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", x);
}
