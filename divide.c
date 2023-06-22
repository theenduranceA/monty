#include "monty.h"

/**
 * m_div - Function that divides the top 2 values on the stack
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	int x, y;

	x = m_args(stack, "div", line_number);
	y = m_args(stack, "div", line_number);

	if (x == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add_node(stack, y / x);
}
