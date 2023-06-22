#include "monty.h"

/**
 * m_pop - Function that removes an element from the stack.
 * @stack: Pointer to the list
 * @line_number: The line number
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = pop_s(stack);

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty %s\n", line_number, user);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	free(node);
}
