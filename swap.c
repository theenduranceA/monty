#include "monty.h"


/**
 * m_swap - Function that swaps the top and last elements
 * @stack: head of the list
 * @line_number: The line number
 *
 */

void m_swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't swap, %s too short\n", line_number, user);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, %s too short\n", line_number, user);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = x;
}
