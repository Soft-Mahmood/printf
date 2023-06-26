#include "main.h"

/**
 * parser receives the main string and all the necessary parameters to 
 * print a formatted string.
 * @ format is the string containing the desired characters.
 * @f_list is the list of the possible functions.
 * @arg_list is a list of all the arguments passed tothe program
 *
 * returns the total count of the characters printed.
 */

int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;
	printed_chars = 0;
	/*Iterate through the main string*/
	for (i = 0; format[i] != '\0'; i++)
	{
		/*checks for specifiers*/
		if (format[i] == '%')
		{
			/*iterates through the struct to find the right function*/
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else 
					return(-1);
			}
			i = i + 1; /*updating to skip format symbols*/
		}
		else 
		{ 
			_write_char(format[i]); /*call the write function*/
			printed_chars++;
		}
	}
	return (printed_chars);
}
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
		{"&", print_percent},
		{NULL, NULL}
	};

	va_list arg_list;
	
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
