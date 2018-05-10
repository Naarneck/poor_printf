/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:33:32 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:33:35 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> //del
#include <stdlib.h>

#define	NONE 0
#define	HH 1
#define	L 2
#define	LL 3
#define	J 4
#define	Z 5
#define	H 6

#define	HASH 0
#define	MINUS 1
#define	PLUS 2
#define	ZERO 3
#define	SPACE 4

#define	END 0
//  sSpdDioOuUxXcC	
//	hh, h, l, ll, j, et z.

//  printf("%-+5,10d", 10);
// % ... # '-+# 0' 6 .10 s
// %[flags] [width] [.precision] [{h | l | ll | w | I | I32 | I64}] type
typedef struct	s_flags
{
	int 		percent;
	int			flags[5];
	int			width;
	int			precision;
	int			cast;
	char		type;
}				t_flags;

typedef struct	s_data
{
	int			printed; //return num
	va_list 	args; //args
	char 		*format; //format line
	int			pos; //curr pos in format
	t_flags		info;
	char 		*arg_string;
}				t_data;

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		digit_count(int value, int base);
char	*ft_itoa_base(int value, int base);
void	print_char(int c, t_data *d);
void	print_string(char *str, t_data *d);
int		ft_printf(char *format, ...);

void	handle_int(t_data *d);

void	handle_width(t_data *d);
#endif