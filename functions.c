#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
    char *op = NULL;
    int n = 0;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    op = strtok(NULL, DELIM);
    if (!op || !stack)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(op);

    new->n = n;
    new->prev = NULL;
    new->next = *stack;

    while (new->next)
    {
    }
}

/**
 * pall - prints all the values of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *value = *stack; /* points to the top, where *stack points too */

    while (value)
    {
        printf("%d\n", value->n);
        value = value->next; /* moves */
    }
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    /* else */
    fprintf(stderr, "%d\n", (*stack)->n);
}

/**
 * pop - removes the top elements of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = NULL;

    if (!*stack) /* case of failure: empty stack */
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = *stack; /*  */
    *stack = (*stack)->next;
    free(tmp);
}