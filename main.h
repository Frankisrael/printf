#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFSIZE	1024

#define ZERO		1
#define PLUS		2
#define DASH		4
#define HASH		8
#define SPACE		16

#define SHORT		1
#define LONG		2

#define FALSE		0
#define TRUE		1

#define NON		-1
#define YES		0

/**
 * struct conversion - A structure of conversion specifiers.
 * @specifier: Character that dictates what specifier function is called.
 * @conv_f: Function pointer.
 */
struct conversion
{
	char specifier;
	int (*conv_f)(va_list arglist, char *buffer, int flags, int width,
			int precision, int l_mod);
};

typedef struct conversion conv_type;

int _printf(const char *format, ...);
int for_formatted(const char *format, int *fmt_ind, va_list arglist,
		char *buffer, int flags, int width, int precision, int l_mod);

int for_c(va_list arglist, char *buffer, int flags, int width, int precision,
		int l_mod);
int for_string(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_percent(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);

int for_int(va_list arglist, char *buffer, int flags, int width, int precision,
		int l_mod);
int for_binary(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_unsigned(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_octal(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_hex_lower(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_hex_upper(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_rev(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_rot13(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_pointer(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int for_custom_S(va_list arglist, char *buffer, int flags, int width,
		int precision, int l_mod);
int ascii_hex_num(char c, char *buffer, int place);

int for_hex(va_list arglist, char *assign, char *buffer, int flags,
		char flag_char, int width, int precision, int l_mod);

int for_flags(const char *format, int *fmt_ind);
int for_width(const char *format, int *fmt_ind, va_list arglist);
int for_precision(const char *format, int *fmt_ind, va_list arglist);
int for_l_mod(const char *format, int *fmt_ind);

int write_char_to_out(char c, char *buffer, int flags, int width,
		int precision, int l_mod);
int write_num(int is_neg, int ind, char *buffer, int flags, int width,
		int precision, int l_mod);
int write_num_to_out(int ind, char *buffer, int flags, int width,
		int precision, int l, char pad, char ex);
int write_pointer_to_out(char *buffer, int ind, int l, int width, int flags,
		char pad_with, char ex, int pad_start);
int write_u_to_out(int is_neg, int ind, char *buffer, int flags, int width,
		int precision, int l_mod);

int for_unprintable_ascii(char *buffer, int buffer_ind, int ascii);
void write_to_out(char *buffer, int *buffer_ind);
long int conv_l_signd(long int num, int l_mod);
long int conv_l_u(unsigned long int num, int l_mod);

#endif /* for MAIN_H */
