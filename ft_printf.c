/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:31:58 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:31:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	print_char(int c, t_data *d)
{
	write(1, &c, 1);
	d->printed++;
}

void	print_string(char *str, t_data *d)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		print_char(str[i], d);
}

int		handle_precision(t_data *d)
{
	//if number
	if (d->format[d->pos] == '*')
	{
	}
	return (1);
}

int		handle_flags(t_data *d)
{
	if (d->format[d->pos] == ' ')
	{
	}
	if (d->format[d->pos] == '0')
	{
	}
	if (d->format[d->pos] == '-')
	{
	}
	if (d->format[d->pos] == '+')
	{
	}
	if (d->format[d->pos] == '#')
	{
	}
	return (1);
}

//remember flags here 
char		identify_type(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{

		if (d->format[d->pos] == 's' || d->format[d->pos] == 'S')
		{
			print_string(va_arg(d->args, char *), d);
			return (0);
		}
		else if (d->format[d->pos] == 'c' || d->format[d->pos] == 'C')
		{
			print_char(va_arg(d->args, int), d);
			return (0);
		}
		d->pos++;
	}
	return (0);
}


void	parse_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{	
		// printf("pos: %d char %c\n", d->pos, d->format[d->pos]);
		if (d->format[d->pos] == '%')
		{
			identify_type(d);
		}
		else
		{
			print_char(d->format[d->pos], d);
		}
		d->pos++;
	}
}

//segfault if no args

int		ft_printf(char *format, ...)
{
	t_data	d;

	d.format = format;
	d.pos = 0;
	d.printed = 0;

	va_start(d.args, format);
	parse_format(&d);
	va_end(d.args);
	return (d.printed);
}
