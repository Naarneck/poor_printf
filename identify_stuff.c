/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:12:38 by izelensk          #+#    #+#             */
/*   Updated: 2018/06/20 17:12:42 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	refresh_flags(t_data *d)
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

int		identify_width(t_data *d)
{
	d->info.flags[WIDTH] = 1;
	while (ft_isdigit(d->format[d->pos], 0) && d->format[d->pos] != '\0')
	{
		d->info.width *= 10;
		d->info.width += d->format[d->pos] - 48;
		d->pos++;
	}
	return (1);
}

int		identify_precision(t_data *d)
{
	d->info.flags[ZERO] = 0;
	d->info.flags[PREC] = 1;
	d->pos++;
	if (!ft_isdigit(d->format[d->pos], 0))
		d->info.precision = 0;
	else
		while (ft_isdigit(d->format[d->pos], 0) && d->format[d->pos] != '\0')
		{
			d->info.precision *= 10;
			d->info.precision += d->format[d->pos] - 48;
			d->pos++;
		}
	return (1);
}

int		identify_flags(t_data *d)
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

void	identify_cast(t_data *d)
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
}
