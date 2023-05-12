#include "monty.h"

/**
 * op_tofunc - chooses the correct function based on the opcode
 * @op: opcode
 */
void (*op_tofunc(char *op))(stack_t **stack, unsigned int line_number)
{
    size_t i = 0;

    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        /* {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop}, */
        {NULL, NULL}};

    while (opcodes[i].opcode) /* i < 2 */
    {
        if (strcmp(op, opcodes[i].opcode))
        {
            return (opcodes[i].f);
        }
        i++;
    }
    return (NULL);
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

    while (str[i])
    {
        if (isdigit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}