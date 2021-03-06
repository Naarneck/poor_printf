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
	if (d->info.precision == 0 && d->info.flags[PREC] && d->arg_string[0] == '0')
	{
		free(d->arg_string);
		d->arg_string = ft_strdup("\0");
	}
}

void	handle_xou(t_data *d) //u o O x X
{
	int n;

	if (d->info.type == 'x' || d->info.type == 'X')
		n = 16;
	else if (d->info.type == 'o' || d->info.type == 'O')
		n = 8;
	else
		n = 10;
	if (d->info.cast == LL || d->info.type == 'U' || d->info.type == 'O')
		d->arg_string = ft_itoa_base_u(va_arg(d->args, unsigned long long int), n);
	else if (d->info.cast == HH)
		d->arg_string = ft_itoa_base_u((unsigned char)va_arg(d->args, uintmax_t), n);
	else if (d->info.cast == H)
		d->arg_string = ft_itoa_base_u((unsigned short int)va_arg(d->args, uintmax_t), n);
	else if (d->info.cast == L )
		d->arg_string = ft_itoa_base_u(va_arg(d->args, unsigned long int), n);
	else if (d->info.cast == J)
		d->arg_string = ft_itoa_base_u(va_arg(d->args, uintmax_t), n);
	else if (d->info.cast == Z)
		d->arg_string = ft_itoa_base_u(va_arg(d->args, size_t), n);
	else
		d->arg_string = ft_itoa_base_u(va_arg(d->args, unsigned int), n);
	if (d->arg_string[0] == '0' && d->info.type != 'o' && d->info.type != 'O')
		d->info.type = 'u'; //ignoring function handle_hash
	if (d->info.flags[PREC] && d->info.precision == 0  && d->arg_string[0] == '0')
	{
		free(d->arg_string);
		d->arg_string = ft_strdup("\0");
	}
}

void	handle_p(t_data *d)
{
	void *p;

	p = va_arg(d->args, void *);
	d->arg_string = ft_itoa_base((intmax_t)p, 16);
	if (d->info.flags[PREC] && d->info.precision == 0  && d->arg_string[0] == '0')
	{
		free(d->arg_string);
		d->arg_string = ft_strdup("\0");
	}
	d->info.flags[HASH] = 1;
	d->info.type = 'x';
}

void	handle_precision(t_data *d)
{
	if (d->info.flags[PREC])
		d->arg_string[d->info.precision] = '\0';
}

void	handle_string(t_data *d)
{
	char *temp;

	temp = va_arg(d->args, char *);
	if (temp == NULL)
	{
		print_string("(null)", d);
		return ;
	}
	d->arg_string = ft_strdup(temp);
	handle_precision(d);
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_percent(t_data *d)
{
	d->arg_string = ft_strdup("%");
	handle_width(d);
	print_string(d->arg_string, d);
}

void	handle_char(t_data *d)
{
	char	temp;
	int		i;

	temp = (char)va_arg(d->args, int);
	if (!d->info.flags[WIDTH])
	{
		print_char(temp, d);
		return ;
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
}
