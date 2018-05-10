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

void	handle_int(t_data *d)
{
	if (d->info.cast == HH)
		d->arg_string = ft_itoa_base((signed char)va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == H)
		d->arg_string = ft_itoa_base((short int)va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == L)
		d->arg_string = ft_itoa_base((long int)va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == LL)
		d->arg_string = ft_itoa_base((long long int)va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == J)
		d->arg_string = ft_itoa_base(va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == Z)
		d->arg_string = ft_itoa_base((size_t)va_arg(d->args, intmax_t), 10);
	else
		d->arg_string = ft_itoa_base((int)va_arg(d->args, intmax_t), 10);
	handle_width(d);
	print_string(d->arg_string, d);
}
