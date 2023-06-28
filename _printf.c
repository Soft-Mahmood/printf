#include "main.h"

/**
 * _printf prints output according to format
 * returns the number of characters on success
 * returns -1 on failure
 */

int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_integer},
		{"r", print_reversed},
		{"R", rot13},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};

	va_list arg_list;
	
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	/*Call the parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
