#include "main.h"

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

