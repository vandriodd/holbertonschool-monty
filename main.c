#include "monty.h"

/**
 * main - main function of monty interpreter
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: 0 on success,
 * exit status on failure
 */
int main(int ac, char **av)
{
    FILE *fd = NULL;
    char *buff = NULL, *op = NULL;
    stack_t *stack = NULL;
    size_t size = 0, line_number = 0;
    void (*f)(stack_t **stack, unsigned int line_number);

    if (ac != 2) /* case of failure: few arguments */
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(av[1], "r");
    if (!fd) /* case of failure: open fails */
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&buff, &size, fd) != -1)
    {
        line_number++;
        op = strtok(buff, DELIM);
        if (!op)
            continue;

        f = op_tofunc(op); /* takes the opcode and calls the function attached */
        if (!f)
        {
            fprintf(stderr, "L%lu unknown instruction %s\n", line_number, op);
            exit(EXIT_FAILURE);
        }
        /* else */
        f(&stack, line_number);
    }
    fclose(fd);
    free(buff);
    free_stack(stack);
    return (0);
}