#include "monty.h"

/**
 * op_tofunc - chooses the correct function based on the opcode
 * @op: opcode
 *
 * Return: function attached to opcode
 */
void (*op_tofunc(char *op))(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
		};

	while (opcodes[i].opcode) /* i < 7 */
	{
		if (strcmp(opcodes[i].opcode, op) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * free_stack - frees stack
 * @stack: pointer to stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack)
	{
		tmp = stack; /* points to current element */
		stack = stack->next; /* moves */
		free(tmp);
	}
}

/**
 * _isdigit - checks for digit
 * @str: string input to be checked
 *
 * Return: 0 if digit, 1 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		str[0] = '0';

	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1); /* valid integer */
}
