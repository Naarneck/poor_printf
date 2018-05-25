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

void refresh_flags(t_data *d)
{
	d->info.percent = 8;
	d->info.width = 0;
	d->info.cast = 0;
	d->info.type = 0;
	d->info.precision = 0;
	while (--d->info.percent)
		d->info.flags[d->info.percent] = 0;
	d->info.flags[d->info.percent] = 0;
}

int		indentify_width(t_data *d)
{
	d->info.flags[WIDTH] = 1;
	while (ft_isdigit(d->format[d->pos]) && d->format[d->pos] != '\0')
	{
		d->info.width *= 10;
		d->info.width += d->format[d->pos] - 48;
		d->pos++;
	}
	return (1);
}

int		indentify_precision(t_data *d)
{
	d->info.flags[ZERO] = 0;
	d->info.flags[PREC] = 1;
	d->pos++;
	if (!ft_isdigit(d->format[d->pos]))
		d->info.precision = 0; //?
	else
		while (ft_isdigit(d->format[d->pos]) && d->format[d->pos] != '\0')
		{
			d->info.precision *= 10;
			d->info.precision += d->format[d->pos] - 48;
			d->pos++;
		}	
	return (1);
}

int		indentify_flags(t_data *d)
{
	if (d->format[d->pos] == ' ')
	{
		d->info.flags[SPACE] = 1;
	}
	else if (d->format[d->pos] == '+')
	{
		d->info.flags[PLUS] = 1;
		d->info.flags[SPACE] = 0;
	}
	else if (d->format[d->pos] == '0')
	{
		d->info.flags[ZERO] = 1;
	}
	else if (d->format[d->pos] == '-')
	{
		d->info.flags[MINUS] = 1;
		d->info.flags[ZERO] = 0;
	}
	else if (d->format[d->pos] == '#')
	{
		d->info.flags[HASH] = 1;
	}
	return (1);
}

//remember flags here

void	indentify_cast(t_data *d)
{
	if (d->format[d->pos] == 'l' && d->format[d->pos + 1] == 'l')
		d->info.cast = LL;
	else if (d->format[d->pos] == 'l')
		d->info.cast = L;
	else if (d->format[d->pos] == 'h' && d->format[d->pos + 1] == 'h')
		d->info.cast = HH;
	else if (d->format[d->pos] == 'h')
		d->info.cast = H;
	else if (d->format[d->pos] == 'j')
		d->info.cast = J;
	else if (d->format[d->pos] == 'z')
		d->info.cast = Z;
	if (d->info.cast != 0)
		d->info.flags[CAST] = 1;
	// printf("- cast %d -", d->info.cast );
}

int	indentify_type(t_data *d)
{
	if (d->format[d->pos] == 's' || d->format[d->pos] == 'S')
	{
		d->info.type = d->format[d->pos];
		// print_string(va_arg(d->args, char *), d);
		handle_string(d);
		return (1);
	}
	else if (d->format[d->pos] == 'c' || d->format[d->pos] == 'C')
	{
		d->info.type = d->format[d->pos];
		// print_char(va_arg(d->args, int), d);
		handle_char(d);
		return (1);
	}
	else if (d->format[d->pos] == 'd' || d->format[d->pos] == 'D' || d->format[d->pos] == 'i')
	{
		d->info.type = d->format[d->pos];
		handle_int(d);
		return (1);
	}
	else if (d->format[d->pos] == 'p')
	{
		d->info.type = d->format[d->pos];
		handle_p(d);
		return (1);
	}
	else if (d->format[d->pos] == 'o' || d->format[d->pos] == 'O')
	{
		d->info.type = d->format[d->pos];
		handle_xou(d);
		return (1);
	}
	else if (d->format[d->pos] == 'x' || d->format[d->pos] == 'X')
	{
		d->info.type = d->format[d->pos];
		handle_xou(d);
		return (1);
	}
	else if (d->format[d->pos] == 'u' || d->format[d->pos] == 'U')
	{
		d->info.type = d->format[d->pos];
		handle_xou(d);
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


char		identify_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{
		/*Check for flags*/
		indentify_flags(d);
		/*Check for width*/
		if (ft_isdigit(d->format[d->pos]))
			indentify_width(d);
		/*Check for precision*/
		if (d->format[d->pos] == '.')
			indentify_precision(d);
		/*Check for hh, h, l, ll, j, et z. first*/
		if (!d->info.flags[CAST])
			indentify_cast(d);
		/*Then check type!*/
		if (indentify_type(d))
			return (1); //to think about it
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
			d->pos++;
			identify_format(d);
			//print arg
			refresh_flags(d);
		}
		else
		{
			print_char(d->format[d->pos], d);
		}
		d->pos++;
	}
}

//segfault if no args, and it's ok

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
