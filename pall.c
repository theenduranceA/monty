#include "monty.h"

/**
 * m_pall - Function that prints all the elements in astack
 * @stack: Pointer to the list
`* @line_number: The line number
 *
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *all;
	(void) line_number;

	if (!stack)
		return;
	all = *stack;
	while (all != NULL)
	{
		printf("%d\n", all->n);
		all = all->next;
	}
}
