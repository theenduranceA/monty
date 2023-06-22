#include "monty.h"

/**
 * m_mod - Function that gets the modulo of the top 2 values
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
	int x, y;

	x = m_args(stack, "mod", line_number);
	y = m_args(stack, "mod", line_number);

	if (x == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add_node(stack, y % x);
}
