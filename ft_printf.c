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

void	print_char()
{
	
}

int	handle_type(t_data *d)
{
	if (d->format[d->pos] == 's')
		printf("handle s here\n");
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
	return ();
}


void	parse_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{	
		if (d->format[d->pos] == '%'){
			++d->pos;
			handle_type(d);
		}
		d->pos++;
	}
}

void	init_data()
{

}

int		ft_printf(const char *format, ...)
{
	t_data	d;

	d.format = format;
	d.pos = 0;

	va_start(d.args, d.format);
	parse_format(&d);
	va_end(d.args);
	return (d.chars);
}