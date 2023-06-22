#include "monty.h"

/**
 * add_node - Function that adds node to the beginning of the stack
 * @stack: Pointer to list
 * @n: value to be added
 * Return: The pointer
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;


	if (!stack)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}


/**
 * add_node_end - Function that adds node at the end
 * @stack: Pointer to the list
 * @n: value to add
 * Return: The pointer of or NULL
 */

stack_t *add_node_end(stack_t **stack, int n)
{
	stack_t *new_node, *opp;

	if (!stack)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*stack)
	{
		for (opp = *stack; opp->next;)
			opp = opp->next;
		new_node->prev = opp;
		opp->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	return (new_node);
}
