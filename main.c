#include "monty.h"

/**
 * main - interpreter
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: ...
 */
int main(int ac, char **av)
{
    char *buff = NULL;
    int fd = 0, size = 0;

    if (ac != 2) /* case of failure */
    {
        fprintf(stderr, "USAGE: monty fail\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(av[1], "r");
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&buff, &size, fd) != -1)
    {
    }
    free(buff);
    fclose(fd);
}