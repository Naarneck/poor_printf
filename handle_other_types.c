/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:15:48 by izelensk          #+#    #+#             */
/*   Updated: 2018/06/20 17:15:50 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_crutch(t_data *d, int a)
{
	if (a)
		if (d->arg_string[0] == '0' && d->info.type != 'o'
			&& d->info.type != 'O')
			d->info.type = 'u';
	if (d->info.flags[PREC] && d->info.precision == 0
													&& d->arg_string[0] == '0')
	{
		free(d->arg_string);
		d->arg_string = ft_strdup("\0");
	}
}

void	handle_int(t_data *d)
{
	if (d->info.cast == J || d->info.type == 'D')
		d->arg_string = ft_itoa_base(va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == HH)
		d->arg_string = ft_itoa_base((signed char)va_arg(d->args, int), 10);
	else if (d->info.cast == H)
		d->arg_string = ft_itoa_base((short int)va_arg(d->args, int), 10);
	else if (d->info.cast == L)
		d->arg_string = ft_itoa_base(va_arg(d->args, long int), 10);
	else if (d->info.cast == LL)
		d->arg_string = ft_itoa_base(va_arg(d->args, long long int), 10);
	else if (d->info.cast == Z)
		d->arg_string = ft_itoa_base(va_arg(d->args, size_t), 10);
	else
		d->arg_string = ft_itoa_base(va_arg(d->args, int), 10);
	zero_crutch(d, 0);
	handle_precision_int(d);
	handle_plus(d);
	handle_hash(d);
	handle_space(d);
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_xou(t_data *d)
{
	int n;

	n = 10;
	if (d->info.type == 'x' || d->info.type == 'X')
		n = 16;
	else if (d->info.type == 'o' || d->info.type == 'O')
		n = 8;
	if (d->info.cast == LL || d->info.type == 'U' || d->info.type == 'O')
		d->arg_string = ft_utoa_base(va_arg(d->args,
													unsigned long long int), n);
	else if (d->info.cast == HH)
		d->arg_string = ft_utoa_base((unsigned char)va_arg(d->args,
																uintmax_t), n);
	else if (d->info.cast == H)
		d->arg_string = ft_utoa_base((unsigned short int)va_arg(d->args,
																uintmax_t), n);
	else if (d->info.cast == L)
		d->arg_string = ft_utoa_base(va_arg(d->args, unsigned long int), n);
	else if (d->info.cast == J)
		d->arg_string = ft_utoa_base(va_arg(d->args, uintmax_t), n);
	else if (d->info.cast == Z)
		d->arg_string = ft_utoa_base(va_arg(d->args, size_t), n);
	else
		d->arg_string = ft_utoa_base(va_arg(d->args, unsigned int), n);
	zero_crutch(d, 1);
}
