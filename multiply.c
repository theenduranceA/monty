#include "monty.h"

/**
 * m_mul - Function that multiplies the top 2 values on the stack
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_mul(stack_t **stack, unsigned int line_number)
{
	int x, y;

	x = m_args(stack, "mul", line_number);
	y = m_args(stack, "mul", line_number);

	add_node(stack, y * x);
}
