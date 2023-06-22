#include "monty.h"

/**
 * m_push - Function that adds an element to the stack
 * @stack: Pointer to the list
 * @line: pointer to the line
 * @line_number: The line number
 *
 * Return: 0 on success -1 on failure
 */

int m_push(stack_t **stack, char *line, unsigned int line_number)
{
	char *c;
	stack_t *node;

	c = m_val(line);
	if (c == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		return (-1);
	};

	if (m_strcmp(user, "stack") == 0)
		node = add_node(stack, atoi(c));
	else
		node = add_node_end(stack, atoi(c));

	free(line);
	if (node == NULL)
	{
		fprintf(stderr,"Error: malloc failed");
		return (-1);
	}
	return (0);
}
