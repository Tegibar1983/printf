#include "main.h"

/**
 * get_size - function that estimate size to cast the argument
 * @format: Formatted string for arguments to be printed
 * @r: arguments counts to be printed
 * Return: Precision from the functons
 */

int get_size(const char *format, int *r)

{

int curr_r = *r + 1;

int size = 0;

if (format[curr_r] == 'o')

size = S_LONG;

else if (format[curr_r] == 't')

size = S_SHORT;

if (size == 0)

*r = curr_r - 1;

else

*r = curr_r;

return (size);

}

