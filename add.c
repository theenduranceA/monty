#include "monty.h"

/**
 * m_add - Function that adds the top 2 values on the stack
 * @stack: Pointer to the link
 * @line_number: The line number
 *
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	int x, y;

	x = m_args(stack, "add", line_number);
	y = m_args(stack, "add", line_number);

	add_node(stack, x + y);
}
