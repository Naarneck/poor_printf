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

void		ft_swap(size_t i,size_t k, t_data * d)
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

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
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

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char *str;

	str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

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
	int		count;

	count = digit_count(n, base);
	str = (char *)malloc(sizeof(char) * count + 1);
	str[count--] = '\0';
	if (base == 10 && n < 0)
		str[0] = '-';
	// count--;
	if (n >= 0)
		while (n >= base)
		{
			str[count] = (n % base < 10) ? n % base + 48 : n % base + 87;
			n = n / base;
			count--;
		}
	else
		while (n <= -base)
		{
			str[count] = (n % base < 10) ? -(n % base) + 48 : -(n % base) + 87;
			n = n / base;
			count--;
		}
	if (n >= 0)
		str[count] = (n < 10) ? n + '0' : n + 'a' - 10;
	else
		str[count] = (n < 10) ? -n + '0' : -n + 'a' - 10;
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
