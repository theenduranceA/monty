#include "monty.h"


/**
 * m_inst - Function that checks the opcode to use
 * @stack: Pointer to the list
 * @line: The op line
 * @line_number: Tge line number
 * Return: 0 on Success, 1 or -1 if other conditions
 */

int m_inst(stack_t **stack, char *line, unsigned int line_number)
{
	instruction_t instr[] = {
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	int x, y;
	char *c;

	c = m_omit(line);
	if (c == NULL)
	{
		free(line);
		return (1);
	}
	if (m_strncmp(c, "push", m_strlen("push")) == 0)
	{
		y = m_push(stack, line, line_number);
		return ((y == 0) ? 0 : -1);
	}
	for (x = 0; instr[x].opcode; x++)
	{
		if (m_strncmp(c, instr[x].opcode, m_strlen(instr[x].opcode)) == 0)
		{
			free(line), (instr[x].f)(stack, line_number);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction ", line_number);
	while (*c && (*c != ' ' && *c != '\t'))
		putchar(*c++);
	putchar('\n');
	free(line);
	return (-1);
}


/**
 * m_args - Function that return the arguments
 * @stack: Pointer to
 * @opcode: The opcodes
 * @line_number: line number
 * Return: The argument
 */

int m_args(stack_t **stack, char *opcode, unsigned int line_number)
{
	stack_t *node;
	int tmp;

	node = pop_s(stack);

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = node->n;
	free(node);
	return (tmp);
}
