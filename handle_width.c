/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:31:58 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:31:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_precision_int(t_data *d)
{
	char	*temp;

	d->cnt = 0;
	d->i = -1;
	while (d->arg_string[++d->i] != '\0')
		if (ft_isdigit(d->arg_string[d->i], 1))
			d->cnt++;
	if (d->info.precision <= d->cnt)
		return ;
	d->cnt = d->info.precision - d->cnt;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(d->arg_string) + d->cnt));
	d->i = 0;
	if (d->arg_string[0] == '-')
	{
		d->cnt--;
		d->arg_string[0] = '0';
		temp[0] = '-';
		d->i++;
	}
	while (d->cnt--)
		temp[d->i++] = '0';
	temp[d->i] = '\0';
	ft_strcat(temp, d->arg_string);
	free(d->arg_string);
	d->arg_string = temp;
}

void	handle_plus(t_data *d)
{
	if ((d->FLAG[PLUS]) && (d->arg_string[0] != '-'))
		insert_prefix("+", d);
}

void	handle_space(t_data *d)
{
	if (d->FLAG[SPACE] && d->arg_string[0] != '-'
												&& d->arg_string[0] != '+')
		insert_prefix(" ", d);
}

void	handle_hash(t_data *d)
{
	size_t		i;

	if (d->FLAG[HASH] && (d->info.type == 'x' || d->info.type == 'X'))
		insert_prefix("0x", d);
	else if (d->FLAG[HASH] && d->arg_string[0] != '0'
		&& (d->info.type == 'o' || d->info.type == 'O'))
		insert_prefix("0", d);
	if (d->info.type == 'X')
	{
		i = ft_strlen(d->arg_string);
		while (i--)
		{
			if (d->arg_string[i] > 96 && d->arg_string[i] < 123)
				d->arg_string[i] -= 32;
		}
	}
}

void	handle_width(t_data *d)
{
	char		*temp;

	if ((size_t)d->info.width <= ft_strlen(d->arg_string))
		return ;
	d->i = 0;
	d->sym = d->info.width - ft_strlen(d->arg_string);
	temp = (char *)malloc(sizeof(char) * ft_strlen(d->arg_string) + d->sym);
	if (!d->FLAG[MINUS])
		while (d->i < d->sym)
			temp[d->i++] = d->FLAG[ZERO] ? '0' : ' ';
	temp[d->i] = '\0';
	ft_strcat(temp, d->arg_string);
	d->i = ft_strlen(d->arg_string) - 1;
	if (d->FLAG[MINUS])
		while (++d->i < ft_strlen(d->arg_string) + d->sym)
			temp[d->i] = ' ';
	if (d->FLAG[MINUS])
		temp[d->i] = '\0';
	free(d->arg_string);
	d->arg_string = temp;
	d->i = 0;
	if (d->arg_string[d->sym] == '0')
		d->i = 1 && d->sym++;
	if (!ft_isdigit(d->arg_string[d->sym], 1) && d->FLAG[3] && !d->FLAG[1])
		ft_swap(d->sym, d->i, d);
}
