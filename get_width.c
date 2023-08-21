#include "main.h"

/**
 * get_width - The function that calculates the width to be printed
 * @format: Formatted string that print arguments
 * @r: arguments lists to be printed
 * @list: parameters of arguments to be printed
 * Return: Width of arguments
 */

int get_width(const char *format, int *r, va_list list)

{

int curr_r;

int width = 0;

for (curr_r = *r + 1; format[curr_r] != '\0'; curr_r++)

{

if (is_digit(format[curr_r]))

{

width *= 10;

width += format[curr_r] - '0';

}

else if (format[curr_r] == '*')

{

curr_r++;

width = va_arg(list, int);

break;

}
else

break;
}

*r = curr_r - 1;

return (width);
}


