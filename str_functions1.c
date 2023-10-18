#include "shell.h"


/**
 * _strdup - Duplicates a string by allocating memory for the duplicate.
 * @str: The string to duplicate.
 * This function takes a string `str` as input and creates a duplicate of it by allocating
 * memory for the duplicated string. The caller is responsible for freeing the memory
 * when it's no longer needed
*/
char *_strdup(const char *str)
{
	int leng = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		leng++;
	ret = malloc(sizeof(char) * (leng + 1));

	if (!ret)
		return (NULL);

	for (leng++; leng--;)
		ret[leng] = *--str;
	return (ret);
}


/**
 * _puts - Prints the contents of a string to the standard output.
 * @str: The string to be printed.
 * This function takes a string `str` as input and outputs its contents to the standard
 * output, typically the console or terminal. It does not return any value, as its main
 * purpose is to display the string to the user.
 * Return: This function does not have a return value.
 */

void _puts(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_putchar(str[w]);
		w++;
	}
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * This function is a fundamental building block for character output. It allows
 * developers to print a single character to the standard output, making it useful
 * for various output operations in C programs.
 * Return: On success, it returns 1, indicating a successful write. On error,
 * it returns -1, and errno is set to provide error information.
 */

int _putchar(char c)
{
	static int e;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)
	{
		write(1, buf, e);
		e = 0;
	}
	if (c != BUF_FLUSH)
		buf[e++] = c;
	return (1);
}


/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination.
 * @src: The source.
 * Return: A pointer to the destination.
 */
char *_strcpy(char *dest, char *src)
{
	int d = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[d])
	{
		dest[d] = src[d];
		d++;
	}
	dest[d] = 0;
	return (dest);
}
