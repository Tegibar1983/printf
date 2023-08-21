#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*** Macro Flags starts with # define ***/

#define F_PLUS 2
#define F_HASH 8
#define F_ZERO 4
#define F_MINUS 1
#define F_SPACE 16

/*** Buffer Sizes ***/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct format Op functions
 * @fmt: formatted charactor data type
 * @fn: function pointer
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - The typedef OP Struct
 * @fmt: The formatted structure
 * @fm_t: formatted function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *r,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*** Header Function prototypes ***/
/*** Print charactor and string functions ***/

int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);


/*** Print Num Functions ***/


int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);



/*** Print non-printable chars function ***/

int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);


/*** Print memory address Functions ***/

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);



/*** Functions that handle other conditional specifiers ***/

int get_precision(const char *format, int *r, va_list list);
int get_flags(const char *format, int *r);
int get_width(const char *format, int *r, va_list list);
int get_size(const char *format, int *r);


/*** print reversed string functions ***/

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);


/*** Function to print rot 13 string ***/

int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);


/*** Print function width hundlers ***/

int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char x, char buffer[],
int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);



/*** Utlis functions***/


long int convert_size_unsgnd(unsigned long int num, int size);
int append_hexa_code(char, char[], int);
int is_printable(char);
long int convert_size_number(long int num, int size);
int is_digit(char);


#endif /*** End of MAIN_H  header file***/
