#include "monty.h"

/**
 * op_inst - function determines  which opcodes should be called.
 * @stack: pointer to a pointer of first node
 * @line_number: the line number in the file.
 */

void op_inst(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	int x;

	for (x = 0; opcodes[x].opcode; x++)
	{
		if (!strcmp(users.token, opcodes[i].opcode))
		{
			users.token = strtok(NULL, " \n");
			opcodes[i].f(stack, line_number);
			break;
		}
	}
	if (!opcodes[i].opcode)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, users.token);
}
