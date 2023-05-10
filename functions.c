#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
    char *token = NULL;
    int n = 0;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL, DELIM);
    if (!token || !stack)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(token); /* stores data */

    new->n = n;
    new->prev = NULL;
    new->next = *stack;

    while (new->next)
    {
        new = new->next;
    }
    *stack = new;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *value = *stack;

    while (value)
    {
        printf("%d\n", value->n);
        value = value->next;
    }
}