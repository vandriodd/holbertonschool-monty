#include "monty.h"

/**
 * sub - subs the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}
