#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 *@input_string: input to be parsed
 *@delim: delimiter to be used, needs to be one character string
 *Return: array of tokens
 */
char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;
	token = _strtok_r(input_string, delim, &save_ptr);
	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}
	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;
	return (av);
}
/**
 *print - prints a string to stdout
 *@string: string to be printed
 *@stream: stream to print out to
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int e = 0;
	for (; string[e] != '\0'; e++)
		write(stream, &string[e], 1);
}
/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *Return: void
 */

void remove_newline(char *str)
{
	int r = 0;
	while (str[r] != '\0')
	{
		if (str[r] == '\n')
			break;
		r++;
	}
	str[r] = '\0';
}
/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 * Return: void
 */
void _strcpy(char *source, char *dest)
{
	int d = 0;
	for (; source[d] != '\0'; d++)
		dest[d] = source[d];
	dest[d] = '\0';
}
/**
 *_strlen - counts string length
 *@string: string to be counted
 * Return: length of the string
 */
int _strlen(char *string)
{
	int length = 0;

	if (string == NULL)
		return (length);
	for (; string[length] != '\0'; length++);
	return (length);
}
