#include "shell.h"

/**
 * _strncat - Concatenates a portion of the second string to the end of the first string.
 * @n: The maximum number of bytes to be used from the second string.
 * @src: The second string.
 * @dest: The first string.
 * This function concatenates the first 'n' bytes from the 'src' string to the end of the 'dest' string.
 * It's a convenient way to combine strings while limiting the number of characters added.
 *
 * Return: The concatenated string in the 'dest' buffer.
 */

char *_strncat(char *dest, char *src, int n)
{
	int g, t;
	char *s = dest;

	g = 0;
	t = 0;
	while (dest[g] != '\0')
		g++;
	while (src[t] != '\0' && t < n)
	{
		dest[g] = src[t];
		g++;
		t++;
	}
	if (t < n)
		dest[g] = '\0';
	return (s);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @c: The character to look for.
 * @s: The string to be searched.
 * 
 * This function scans the 's' string and returns a pointer to the first occurrence
 * of the character 'c'. It's a valuable tool for finding specific characters in a string.
 * Return: A pointer to the memory area of 's' where 'c' is found, or NULL if 'c' is not present.
 */

char *_strchr(char *s, char d)
{
	do {
		if (*s == d)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strncpy - Copies a portion of a source string to a destination string.
 * @src: The source string.
 * @n: The number of characters to be copied.
 * @dest: The destination string to be copied to.
 *
 * This function copies the first 'n' characters from the 'src' string to the 'dest' string.
 * It's a useful tool for controlled string copying operations.
 * Return: The destination string after the copying is complete.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int e, r;
	char *s = dest;
	e = 0;
	while (src[e] != '\0' && e < n - 1)
	{
		dest[e] = src[e];
		e++;
	}
	if (e < n)
	{
		r = e;
		while (r < n)
		{
			dest[r] = '\0';
			r++;
		}
	}
	return (s);
}




