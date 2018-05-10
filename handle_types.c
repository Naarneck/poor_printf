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
	if (d->info.cast == NONE)
		d->arg_string = ft_itoa_base(va_arg(d->args, int), 10);
	else if (d->info.cast == HH)
		d->arg_string = ft_itoa_base(va_arg(d->args, signed char), 10);
	else if (d->info.cast == H)
		d->arg_string = ft_itoa_base(va_arg(d->args, short int), 10);
	else if (d->info.cast == L)
		d->arg_string = ft_itoa_base(va_arg(d->args, long int), 10);
	else if (d->info.cast == LL)
		d->arg_string = ft_itoa_base(va_arg(d->args, long long int), 10);
	else if (d->info.cast == J)
		d->arg_string = ft_itoa_base(va_arg(d->args, intmax_t), 10);
	else if (d->info.cast == Z)
		d->arg_string = ft_itoa_base(va_arg(d->args, size_t), 10);
	handle_width(d);
	print_string(d->arg_string, d);
}
