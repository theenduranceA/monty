#include "monty.h"

/**
 * m_rotl - Function that switches the top element of the stack to the back
 * @stack: pointer to the list
 * @line_number: The line number
 *
 */

void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *up;
	stack_t *dwn;

	(void) line_number;

	if (!stack || !*stack)
		return;
	if (!(*stack)->next)
		return;

	up = pop_s(stack);
	up->next = NULL;

	dwn = *stack;
	while (dwn->next)
		dwn = dwn->next;
	dwn->next = up;
	up->prev = dwn;
}
