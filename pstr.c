#include "monty.h"

/**
 * m_pstr - Print all the strings in a stack as chars
 * @stack: Pointer to the list
 * @line_number: The line number
 *
 */

void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *all;
	(void) line_number;

	if (stack != NULL)
	{
		all = *stack;
		while (all != NULL && all->n > 0 && all->n < 127)
		{
			printf("%c", all->n);
			all = all->next;
		}
	}
	putchar('\n');
}
