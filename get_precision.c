#include "main.h"

/**
* get_precision - Function that calculates printing precision
* @format: Pramater of arrays of chars
* @r: Paramters or arguments to be printed
* @list: Argumets lists or counts
* Return: Printing precision levels
*/

int get_precision(const char *format, int *r, va_list list)
{
int curr_r = *r + 1;
int precision = -1;
if (format[curr_r] != '.')
return (precision);
precision = 0;
for (curr_r += 1; format[curr_r] != '\0'; curr_r++)
{
if (is_digit(format[curr_r]))
{
precision *= 10;
precision += format[curr_r] - '0';
}
else if (format[curr_r] == '*')
{
curr_r++;
precision = va_arg(list, int);
break;
}
else
break;
}
*r = curr_r - 1;
return (precision);
}
