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

void	insert_prefix(const char *pref, t_data *d)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(d->arg_string)
												+ ft_strlen(pref)));
	i = -1;
	while (pref[++i] != '\0')
		temp[i] = pref[i];
	temp[i] = '\0';
	ft_strcat(temp, d->arg_string);
	free(d->arg_string);
	d->arg_string = temp;
}

void	handle_precision_int(t_data *d)
{
	int		i;
	int		cnt;
	char	*temp;

	cnt = 0;
	i = -1;
	while (d->arg_string[++i] != '\0')
		if (ft_isdigit(d->arg_string[i]) || (d->arg_string[i] > 96
										&& d->arg_string[i] < 103))
			cnt++;
	i = 0;
	if (d->info.precision <= cnt)
		return ;
	cnt = d->info.precision - cnt;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(d->arg_string) + cnt));
	if (d->arg_string[0] == '-')
	{
		cnt--;
		d->arg_string[0] = '0';
		temp[0] = '-';
		i++;
	}
	while (cnt--)
		temp[i++] = '0';
	temp[i] = '\0';
	ft_strcat(temp, d->arg_string);
	free(d->arg_string);
	d->arg_string = temp;
}

void	handle_plus(t_data *d)
{
	if ((d->info.flags[PLUS]) && (d->arg_string[0] != '-'))
		insert_prefix("+", d);
}

void	handle_space(t_data *d)
{
	if (d->info.flags[SPACE] && d->arg_string[0] != '-' && d->arg_string[0] != '+')
		insert_prefix(" ", d);
}

void	handle_hash(t_data *d)
{
	size_t		i;

	if (d->info.flags[HASH] && (d->info.type == 'x' || d->info.type == 'X'))
		insert_prefix("0x", d);
	else if (d->info.flags[HASH] && d->arg_string[0] != '0'
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
	size_t		i;

	if ((size_t)d->info.width > ft_strlen(d->arg_string))
	{
		i = 0;
		d->sym = d->info.width - ft_strlen(d->arg_string);
		temp = (char *)malloc(sizeof(char) * (ft_strlen(d->arg_string) + d->sym));
		if (!d->info.flags[MINUS])
		{
			i = -1;
			while (++i < d->sym)
				if (d->info.flags[ZERO])
					temp[i] = '0';
				else
					temp[i] = ' ';
		}
		temp[i] = '\0';
		ft_strcat(temp, d->arg_string);
		if (d->info.flags[MINUS])
		{
			i = ft_strlen(d->arg_string) - 1;
			while (++i < ft_strlen(d->arg_string) + d->sym)
				temp[i] = ' ';
			temp[i] = '\0';
		}
		free(d->arg_string);
		d->arg_string = temp;
		i = 0;
		if (d->arg_string[d->sym] == '0')
			i = 1 && d->sym++;
		if (!(ft_isdigit(d->arg_string[d->sym]) || (d->arg_string[d->sym] > 96
		&& d->arg_string[d->sym] < 103)) && d->info.flags[ZERO] && !d->info.flags[MINUS])
			ft_swap(d->sym, i, d);
	}
}
