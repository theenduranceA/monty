#include "monty.h"

/**
 * m_sub - Function that subtracts the top 2 values on the stack
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	int x, y;

	x = m_args(stack, "sub", line_number);
	y = m_args(stack, "sub", line_number);

	add_node(stack, y - x);
}
