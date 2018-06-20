/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:13:39 by izelensk          #+#    #+#             */
/*   Updated: 2018/06/20 17:13:41 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digit_count(intmax_t n, int base)
{
	int i;

	if (base == 10 && n < 0)
		i = 2;
	else
		i = 1;
	if (n >= 0)
		while (n >= base)
		{
			n = n / base;
			i++;
		}
	else
		while (n <= -base)
		{
			n = n / base;
			i++;
		}
	return (i);
}

char	*ft_itoa_base(intmax_t n, int base)
{
	char	*str;
	int		cnt;

	cnt = digit_count(n, base);
	str = (char *)malloc(sizeof(char) * cnt + 1);
	str[cnt--] = '\0';
	if (base == 10 && n < 0)
		str[0] = '-';
	if (n >= 0)
		while (n >= base)
		{
			str[cnt--] = (n % base < 10) ? n % base + 48 : n % base + 87;
			n = n / base;
		}
	else
		while (n <= -base)
		{
			str[cnt--] = (n % base < 10) ? -(n % base) + 48 : -(n % base) + 87;
			n = n / base;
		}
	if (n >= 0)
		str[cnt] = (n < 10) ? n + '0' : n + 'a' - 10;
	else
		str[cnt] = (n < 10) ? -n + '0' : -n + 'a' - 10;
	return (str);
}

int		digit_count_u(uintmax_t n, int base)
{
	int	i;

	i = 1;
	while (n >= (uintmax_t)base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_utoa_base(uintmax_t n, int base)
{
	char	*str;
	int		count;

	count = digit_count_u(n, base);
	str = (char *)malloc(sizeof(char) * count + 1);
	str[count] = '\0';
	count--;
	while (n >= (uintmax_t)base)
	{
		str[count] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n = n / base;
		count--;
	}
	if (n < 10)
		str[count] = n + '0';
	else
		str[count] = n + 'a' - 10;
	return (str);
}
