#include "monty.h"

/**
 * rm_buff - Function that removes buffer.
 * @buffer: The buffer
 * @size: Size of the buffer
 */

void rm_buff(char *buffer, size_t size)
{
	size_t x;

	for (x = 0; x < size; x++)
		buffer[x] = '\0';
}

/**
 * fill_buff - Function that fills buffer with '\0' char
 * @buf: Pointer to the buffer
 * @size: pointer to the size
 * @c: char to be inserted at index
 * @index: index to enter char
 *
 */

void fill_buff(char **buf, size_t *size, char c, size_t index)
{
	char *x;

	if (!buf || !size)
		return;
	if (index >= *size - 1)
	{
		*buf = realloc(*buf, *size * 2);
		if (*buf == NULL)
			return;
		*size = *size * 2;
	}
	x = *buf;
	*(x + index) = c;
}

/**
 * m_getline - Function that reads a line from standard input
 * @buf: Pointer to the buffer
 * @size: size of buffer
 * @file_strm: input stream
 * Return: number of chars read on success,
 * -1 if otherwise
 */

ssize_t m_getline(char **buf, size_t *size, int file_strm)
{
	size_t n;
	char c;
	int x;

	if (!buf || !size)
		return (-1);
	if (!*buf)
	{
		*size = BUF_LENGTH;
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}
	n = 0;
	rm_buff(*buf, *size);
	while (1)
	{
		x = read(file_strm, &c, 1);
		if (x == -1)
			return (-1);
		if (x == 0 && n == 0)
			return (-1);
		if (c != EOF)
		{
			fill_buff(buf, size, c, n);
			if (*buf == NULL)
				return (-1);
			n++;
		}
		if (c == '\n')
			break;
	}
	*((*buf) + n - 1) = '\0';

	return (n);
}
