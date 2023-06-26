#include "main.h"

/**
 * _write_char writes the character to stdout
 * @c is the character to print
 * returns 1 on success
 * returns -1 on failure
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char prints a chahacter
 * @list is the list of arguments
 * returns the amount of characters printed
 */

int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string prints a string
 * returns the number of characters printed
 */

int print_string(va_list list)
{
	int i;
	char *str;
	
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(NULL)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
	return (i);
}

/**
 * print_percent prints the % symbol
 * returns the number of characters printed
 */

int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return(1);
}
