/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:31:58 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:31:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_p(t_data *d)
{
	void *p;

	p = va_arg(d->args, void *);
	d->arg_string = ft_itoa_base((intmax_t)p, 16);
	if (d->info.flags[PREC] && d->info.precision == 0
													&& d->arg_string[0] == '0')
	{
		free(d->arg_string);
		d->arg_string = ft_strdup("\0");
	}
	d->info.flags[HASH] = 1;
	d->info.type = 'x';
	handle_precision_int(d);
	handle_hash(d);
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_precision(t_data *d)
{
	if (d->info.flags[PREC])
		d->arg_string[d->info.precision] = '\0';
}

int		handle_string(t_data *d)
{
	char *temp;

	temp = va_arg(d->args, char *);
	if (temp == NULL)
	{
		print_string("(null)", d);
		return (0);
	}
	d->arg_string = ft_strdup(temp);
	handle_precision(d);
	handle_width(d);
	print_string(d->arg_string, d);
	return (1);
}

void	handle_percent(t_data *d)
{
	d->arg_string = ft_strdup("%");
	handle_width(d);
	print_string(d->arg_string, d);
}

int		handle_char(t_data *d)
{
	char	temp;
	int		i;

	temp = (char)va_arg(d->args, int);
	if (!d->info.flags[WIDTH])
	{
		print_char(temp, d);
		return (0);
	}
	i = 0;
	if (!d->info.flags[MINUS])
	{
		while (i++ < d->info.width - 1)
			print_char(' ', d);
		print_char(temp, d);
	}
	else if (d->info.flags[MINUS])
	{
		print_char(temp, d);
		while (i++ < d->info.width - 1)
			print_char(' ', d);
	}
	return (1);
}
