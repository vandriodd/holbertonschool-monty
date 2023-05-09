#include "monty.h"

/**
 * main -
 * @ac: argument counter
 * @av: argument vector
 *
 * Return:
 */
int main(int ac, char **av)
{
    char *buff = NULL;
    int fd = 0, size = 0;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty fail\n");
        exit(EXIT_FAILURE);
    }

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&buff, &size, fd) != -1)
    {
    }
    close(fd);
}