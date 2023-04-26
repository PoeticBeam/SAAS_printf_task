#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
​
#define UNUSED(x) (void)(x)
#define BUFFER 1024
​
/*
 * ALL FLAG(S) present
 */
#define FL_MINUS 1
#define FL_PLUS 2
#define FL_0 4
#define FL_HASHTAG 8
#define FL_SPACE 16
​
/*
 * USED SIZES
 */
#define SIZE_LONG 2
#define SIZE_SHORT 1
​
/**
 * struct frmt - Struct ap
 *
 * @frmt: format specifiers
 * @func: function to call per format specifier
 */
struct frmt
{
	char frmt;
	int (*func)(va_list, char[], int, int, int, int);
};
​
​
/**
 * typedef struct frmt frmt - Struct ap
 *
 * @frmt: format specifiers
 * @frmtt: typedef newly defined function.
 */
typedef struct frmt frmtt;
​
int _printf(const char *format, ...);
int handle_print(const char *frmt, int *ii,
		va_list list, char buffer[], int flag, int width, int accuracy, int size);
​
/************** ALL FUNCTIONS USED ***************/
​
/* These functions print characters + strings */
int prnt_char(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_str(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_prcent(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
/* These functions print numbers */
int prnt_integer(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_binary(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_unsgnd(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_oktal(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_hexadec(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
int prnt_hexadec_upper(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
int prnt_hexa(va_list typ, char mapsto[],
		char buffer[], int flag, char flag_chter, int width, int accuracy, int size);
​
/* This function is defined to print the non-printable characters */
int prnt__the_not_printable(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
/* this function will print memory address */
int prnt_ptr(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
/* These functions check for the other format specifiers */
int scan_flag(const char *format, int *ii);
int scan_width(const char *format, int *ii, va_list list);
int scan_accuracy(const char *format, int *ii, va_list list);
int scan_size(const char *format, int *ii);
​
/* This function will print a string in reverse */
int prnt_rev(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
/* This function will print a string in rot 13 encryption*/
int prnt_inrot13(va_list typ, char buffer[],
		int flag, int width, int accuracy, int size);
​
/* list of width handler functions */
int write_char_handler(char k, char buffer[],
		int flag, int width, int accuracy, int size);
int write_numbr(int positive, int ind, char buffer[],
		int flag, int width, int accuracy, int size);
int write_num(int ind, char bff[], int flag, int width, int accuracy,
		int leng, char padding, char xtra_char);
int write_ptr(char buffer[], int ind, int leng,
		int width, int flag, char padding, char xtra_char, int padding_start);
​
int write_unsgnd(int negative, int ind,
		char buffer[],
		int flag, int width, int accuracy, int size);
​
/************** utilities **************/
int printable(char);
int hexa_code_appended(char, char[], int);
int digit(char);
​
long int size_number_conversion(long int n, int size);
long int size_unsigned_conversion(unsigned long int n, int size);
​
#endif /* MAIN_H */

