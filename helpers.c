#include "holberton.h"

/**
 * @height: int for height of 2Dim array to be passed
 * @grid: Char double pointer to be freed
 * free_grid - function that frees a 2d grid of int poi
 * Return: void or null
 */
void free_grid(char **grid, int height)
{int y;
	for (y = 0; y < height; y++)
		free(grid[y]);
	free(grid);
}
/**
 * @l: line
 * no_nl - removes the line with the NULL character
 * Return: nothing to return
 */
void no_nl(char *l)
{
	int h = 0;
	while (l[h])
	{
		if (l[h] == '\n')
		{
			l[h] = '\0';
			return;
		}h++;
	}
}


/**
 * it carries out the command when the user keep on tabbing
 * special_char -  control d, it will exit the shell and handles
 * @bytes: the number of bytes 
 * @buffer: the buffer we use 
 * @ex_st: the exit status the show status
 * Return: (0) for complet
 */
int  special_char(char *buffer, ssize_t bytes, int *ex_st)
{
	int f = 0;
    if (bytes == EOF && isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(buffer);
		exit(*ex_st);
	}if (bytes == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*ex_st);
	}if (_strcmp(buffer, "\n") == 0)
	{
		*ex_st = 0;
		return (127);
	}while (buffer[f] != '\n')
	{
		if (buffer[f] != ' ' && buffer[f] != '\t')
			return (0);

		++f;
	}
	*ex_st = 0;
	return (127);
}
