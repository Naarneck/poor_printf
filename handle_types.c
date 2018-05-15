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

void	handle_int(t_data *d) //d D i
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

void	handle_xou(t_data *d) //u o O x X
{
	int n;

	if (d->info.type == 'x' || d->info.type == 'X')
		n = 16;
	else if (d->info.type == 'o' || d->info.type == 'O')
		n = 8;
	else if (d->info.type == 'u' || d->info.type == 'U')
		n = 10;  
	if (d->info.cast == HH)
		d->arg_string = ft_itoa_base((unsigned char)va_arg(d->args, intmax_t), n);
	else if (d->info.cast == H)
		d->arg_string = ft_itoa_base((unsigned short int)va_arg(d->args, intmax_t), n);
	else if (d->info.cast == L)
		d->arg_string = ft_itoa_base((unsigned long int)va_arg(d->args, intmax_t), n);
	else if (d->info.cast == LL)
		d->arg_string = ft_itoa_base((unsigned long long int)va_arg(d->args, intmax_t), n);
	else if (d->info.cast == J)
		d->arg_string = ft_itoa_base(va_arg(d->args, intmax_t), n);
	else if (d->info.cast == Z)
		d->arg_string = ft_itoa_base((size_t)va_arg(d->args, intmax_t), n);
	else
		d->arg_string = ft_itoa_base((unsigned int)va_arg(d->args, intmax_t), n);
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_precision(t_data *d)
{
	if (d->info.flags[PREC])
		d->arg_string[d->info.precision] = '\0';
}

void	handle_string(t_data *d)
{
	d->arg_string = ft_strdup(va_arg(d->args, char *));
	handle_precision(d);
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_percent(t_data *d)
{
	d->arg_string = ft_strdup("%");
	handle_width(d);
	// handle_precision(d);
	print_string(d->arg_string, d);
}