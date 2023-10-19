#include "main.h"

/**
 * print_binary - Prints unsigned int in binary form
 * @num: Unsigned Int Parameter
 * Return: The number counter
 */

int print_binary(unsigned int num)
{
	/* A buffer to store the bin representation */
	char binary[32];
	int i, bin_count;

	if (num == 0)
		return (print_char('0'));

	i = 0;
	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num /= 2;
	}

	bin_count = 0;
	while (i > 0)
	{
		bin_count += print_char(binary[--i]);
	}

	return (bin_count);
}

/**
 * print_ui - Outputs unsigned numbers
 * @num: The parameter to handle
 * Return: The number counter
 */
int print_ui(unsigned int num)
{
	char decimal[32];
	int i, unsigned_count;

	if (num == 0)
		return (print_char('0'));

	i = 0;
	while (num > 0)
	{
		decimal[i++] = (num % 10) + '0';
		num /= 10;
	}

	unsigned_count = 0;
	while (i > 0)
	{
		unsigned_count += print_char(decimal[--i]);
	}

	return (unsigned_count);
}

/**
 * print_octal - convert and output a num into its octal
 * @num: unsigned number
 * Return: The octal counter
 */
int print_octal(unsigned int num)
{
	char octal[32];
	int i, octal_count;

	if (num == 0)
		return (print_char('0'));

	i = 0;
	while (num > 0)
	{
		octal[i++] = (num % 8) + '0';
		num /= 8;
	}

	octal_count = 0;
	while (i > 0)
	{
		octal_count += print_char(octal[--i]);
	}

	return (octal_count);
}
