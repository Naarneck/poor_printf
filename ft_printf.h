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
#define FT_PRINTF ft_printf
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> //del
#define	H 0
#define	HH 1
#define	L 2
#define	LL 3
#define	J 4
#define	Z 5

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
	int			type;
}				t_flags;

typedef struct	s_data
{
	int			printed; //return num
	va_list 	args; //args
	char 		*format; //format line
	int			pos; //curr pos in format
	t_flags		info;
}				t_data;


#endif