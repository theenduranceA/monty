#include "monty.h"

/**
 * m_pint - Function that peeks the top of the stack
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_pint(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
