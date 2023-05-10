#include "monty.h"

/**
 * get_func - chooses the correct function based on the input
 * @op: opcode
 *
 * Return: the function corresponding to the opcode,
 * 0 otherwise
 */
int (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	while (i < 2)
	{
		if (!strcmp(op, opcodes[i].opcode))
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return (0);
}