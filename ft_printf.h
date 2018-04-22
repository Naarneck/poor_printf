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

//  sSpdDioOuUxXcC

#define	

typedef struct	s_data
{
	int			chars; //return num
	va_list 	args; //args
	char 		*format; //format line
	int			pos;
}				t_data;

#endif