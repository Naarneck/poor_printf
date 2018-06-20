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

int		identify_other_types(t_data *d)
{
	if (d->format[d->pos] == 'x' || d->format[d->pos] == 'X' ||
	d->format[d->pos] == 'u' || d->format[d->pos] == 'U' ||
	d->format[d->pos] == 'o' || d->format[d->pos] == 'O')
	{
		d->info.type = d->format[d->pos];
		handle_xou(d);
		handle_precision_int(d);
		handle_hash(d);
		handle_width(d);
		print_string(d->arg_string, d);
		return (1);
	}
	else if (d->format[d->pos] == '%')
	{
		d->info.type = d->format[d->pos];
		handle_percent(d);
		return (1);
	}
	return (0);
}

int		identify_type(t_data *d)
{
	if (d->format[d->pos] == 's' || d->format[d->pos] == 'S')
	{
		handle_string(d);
		return (1);
	}
	else if (d->format[d->pos] == 'c' || d->format[d->pos] == 'C')
	{
		handle_char(d);
		return (1);
	}
	else if (d->format[d->pos] == 'd' || d->format[d->pos] == 'D'
		|| d->format[d->pos] == 'i')
	{
		d->info.type = d->format[d->pos];
		handle_int(d);
		return (1);
	}
	else if (d->format[d->pos] == 'p')
	{
		handle_p(d);
		return (1);
	}
	else if (identify_other_types(d))
		return (1);
	return (0);
}

char	identify_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{
		if (!valid_spec(d))
		{
			print_char(d->format[d->pos], d);
			return (2);
		}
		identify_flags(d);
		if (ft_isdigit(d->format[d->pos], 0) && d->format[d->pos] != '0')
			identify_width(d);
		if (d->format[d->pos] == '.')
			identify_precision(d);
		if (!d->info.flags[CAST])
			identify_cast(d);
		if (identify_type(d))
			return (1);
		d->pos++;
	}
	return (0);
}

void	parse_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{
		if (d->format[d->pos] == '%')
		{
			d->pos++;
			if (!identify_format(d))
				return ;
			refresh_flags(d);
		}
		else
			print_char(d->format[d->pos], d);
		d->pos++;
	}
}

int		ft_printf(char *format, ...)
{
	t_data	d;

	d.format = format;
	d.pos = 0;
	d.printed = 0;
	refresh_flags(&d);
	va_start(d.args, format);
	parse_format(&d);
	va_end(d.args);
	return (d.printed);
}
