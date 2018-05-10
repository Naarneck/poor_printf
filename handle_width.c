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

void	handle_width(t_data *d)
{
	char	*temp;
	int		sym;
	int		i;

	if ((size_t)d->info.width > ft_strlen(d->arg_string) && !d->info.flags[MINUS])
	{
		sym = d->info.width - ft_strlen(d->arg_string);
		temp = (char *)malloc(sizeof(char) * ft_strlen(d->arg_string) + sym);
		i = -1;
		while (++i < sym)
		{
			if (d->info.flags[ZERO])
				temp[i] = '0';
			else
				temp[i] = ' ';
		}
		temp[i] = '\0';
		ft_strcat(temp, d->arg_string);
		free(d->arg_string);
		d->arg_string = temp;
	}
}