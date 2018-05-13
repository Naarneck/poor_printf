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

void	handle_plus(t_data *d)
{
	char	*temp;

	if (d->info.flags[PLUS] && d->arg_string[0] != '-')
	{
		temp = (char *)malloc(sizeof(char) * ft_strlen(d->arg_string) + 1);
		temp[0] = '+';
		temp[1] = '\0';
		ft_strcat(temp, d->arg_string);
		free(d->arg_string);
		d->arg_string = temp;
	}
}

void	handle_sharp(t_data *d)
{
	char	*temp;
	size_t		i;
	
	if (d->info.flags[HASH] && (d->info.type == 'X' || d->info.type == 'x'))
	{
		temp = (char *)malloc(sizeof(char) * ft_strlen(d->arg_string) + 2);
		temp[0] = '0';
		temp[1] = 'x';
		temp[2] = '\0';
		ft_strcat(temp, d->arg_string);
		free(d->arg_string);
		d->arg_string = temp;
	}
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
	char	*temp;
	size_t		i;
	char	c;

	handle_plus(d);
	handle_sharp(d);
	if ((size_t)d->info.width > ft_strlen(d->arg_string))
	{
		i = 0;
		d->sym = d->info.width - ft_strlen(d->arg_string);
		temp = (char *)malloc(sizeof(char) * ft_strlen(d->arg_string) + d->sym);
		if  (!d->info.flags[MINUS])
		{
			i = -1;
			while (++i < d->sym)
			{
				if (d->info.flags[ZERO])
					temp[i] = '0';
				else
					temp[i] = ' ';
			}
		}
		temp[i] = '\0';
		ft_strcat(temp, d->arg_string);
		if  (d->info.flags[MINUS])
		{
			i = ft_strlen(d->arg_string) - 1;
			while (++i < ft_strlen(d->arg_string) + d->sym)
			{
				temp[i] = ' ';	
			}
			temp[i] = '\0';
		}		
		free(d->arg_string);
		d->arg_string = temp;
		if (!ft_isdigit(d->arg_string[d->sym]) && d->info.flags[ZERO] && !d->info.flags[MINUS])
		{
			c = d->arg_string[d->sym];
			d->arg_string[d->sym] = d->arg_string[0];
			d->arg_string[0] = c;
		}
	}
}