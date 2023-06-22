#include "monty.h"

/**
 * m_rotr - Function that switches the last element to the top of the stack
 * @stack: Pointer to list
 * @line_number: The line number
 *
 */

void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *up;

	(void)line_number;

	if (!stack || !*stack)
		return;
	if (!(*stack)->next)
		return;

	up = dequeue(stack);
	up->prev = NULL;

	up->next = *stack;
	(*stack)->prev = up;
	*stack = up;
}
