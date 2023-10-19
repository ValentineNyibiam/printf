#include "main.h"

/**
 * print_Hex - In capital letters
 * @num: The parameter to convert
 * Return: The hex counter
 */
int print_Hex(unsigned int num)
{
	char Hex[32];
	int i, Hex_count;

	if (num == 0)
		return (print_char('0'));

	char Hexchars[] = "0123456789ABCDEF";

	i = 0;
	while (num < 0)
	{
		Hex[i++] = Hexchars[num % 16];
		num /= 16;
	}

	Hex_count = 0;
	while (i > 0)
	{
		Hex_count += print_char(Hex[--i]);
	}

	return (Hex_count);
}
