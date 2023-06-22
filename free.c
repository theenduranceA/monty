#include "monty.h"

/**
 * free_stack - Function that frees the elements in the stack
 * @stack: Pointer to a the list
 */

void free_stack(stack_t *stack)
{
	stack_t *opp;


	while (stack != NULL)
	{
		opp = stack;
		stack = stack->next;
		free(opp);
	}
}



/**
 * pop_s - Function that return the node
 * @stack: Pointer to the list
 * Return: The pointer or NULL
 */

stack_t *pop_s(stack_t **stack)
{
	stack_t *opp;

	if (!stack || !*stack)
		return (NULL);

	opp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;


	return (opp);
}


/**
 * dequeue - Function that returns the node to the end
 * @head: Pointer to the list
 * Return: The Pointer or NULL
 */

stack_t *dequeue(stack_t **stack)
{
	stack_t *opp;

	if (!stack || !*stack)
		return (NULL);

	opp = *stack;
	while (opp->next != NULL)
		opp = opp->next;

	if (opp->prev)
		(opp->prev)->next = NULL;
	else
		*stack = NULL;

	return (opp);
}
