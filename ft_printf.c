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

int 	check_width(t_data *d)
{
	write(1, &d->format[d->pos],1);
}

//segfault if no args

void	print_string(t_data *d, char *str)
{
	printf("::print_string invoke\n");
	printf("%s\n", str); //putsr here
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


int		handle_type(t_data *d)
{
	if (d->format[d->pos] == 's'){
		print_string(d, va_arg(d->args, char *));
	}
	if (d->format[d->pos] == 'S')
		printf("handle S here\n");
	if (d->format[d->pos] == 'p')
		printf("handle p here\n");
	if (d->format[d->pos] == 's')
		printf("handle d here\n");
	if (d->format[d->pos] == 's')
		printf("handle D here\n");
	if (d->format[d->pos] == 's')
		printf("handle o here\n");
	if (d->format[d->pos] == 's')
		printf("handle O here\n");
	if (d->format[d->pos] == 's')
		printf("handle u here\n");
	if (d->format[d->pos] == 's')
		printf("handle U here\n");
	if (d->format[d->pos] == 's')
		printf("handle x here\n");
	if (d->format[d->pos] == 's')
		printf("handle X here\n");
	if (d->format[d->pos] == 's')
		printf("handle c here\n");
	if (d->format[d->pos] == 's')
		printf("handle C here\n");
	return (1);
}


void	parse_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{	
		if (d->format[d->pos] == '%')
		{
			++d->pos;
			handle_type(d);
		}
		else
		{
			write(1, &d->format[d->pos],1);
			d->printed++;	
		}
		d->pos++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_data	d;

	d.format = format;
	d.pos = 0;
	d.printed = 0;

	va_start(d.args, d.format);
	parse_format(&d);
	va_end(d.args);
	return (d.printed);
}
