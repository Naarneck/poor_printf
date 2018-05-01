/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:31:58 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:31:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		f;
	long	res;

	f = 0;
	i = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		f += 1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (f == 1)
		return (-res);
	else
		return (res);
}


int		digit_count(int value, int base)
{
	int i;
	long long  n;

	n = value;
	i = 1;
	if (base == 10 && value < 0)
	{
		n = n * (-1);
		i = 2;
	}
	if (base != 10 && value < 0)
	{
		n = n * (-1);
	}
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	long long n;
	char *str;
	int count;
   
	count = digit_count(value, base);
	n = value;
	str = (char *)malloc(sizeof(char) * count + 1);
	str[count] = '\0';
	if (base == 10 && value < 0)
	{;
		n = n * (-1);
		str[0] = '-';
	}
	if (base != 10 && value < 0)
	{
		n = n * (-1);
	}
	count--;
	while (n >= base)
	{
		if (n % base < 10)
			str[count] = n % base + '0';
		if (n % base >= 10)
			str[count] = n % base + 'A' - 10;
		n = n / base;
		count--;
	}
	if (n  < 10)
		str[count] = n + '0';
	else
		str[count] = n + 'A' - 10;
	return(str);
}

void	print_char(int c, t_data *d)
{
	write(1, &c, 1);
	d->printed++;
}

void	print_string(char *str, t_data *d)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		print_char(str[i], d);
}
