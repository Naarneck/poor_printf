/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:13:44 by izelensk          #+#    #+#             */
/*   Updated: 2018/06/20 17:13:46 by izelensk         ###   ########.fr       */
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

void	ft_swap(size_t i, size_t k, t_data *d)
{
	char	c;

	c = d->arg_string[k];
	d->arg_string[k] = d->arg_string[i];
	d->arg_string[i] = c;
}

int		valid_spec(t_data *d)
{
	char	*str;
	int		i;

	i = 0;
	str = "sSpdDioOuUxXcC% #+-0hljz.*123456789";
	while (str[i] != '\0')
	{
		if (d->format[d->pos] == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_isdigit(char c, int letters)
{
	if (letters == 0)
		if (c > 47 && c < 58)
			return (1);
	if (letters == 1)
		if ((c > 47 && c < 58) || (c > 96 && c < 103))
			return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
