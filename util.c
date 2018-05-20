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

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t			i;
// 	char			*temp;

// 	temp = (char *)b;
// 	i = 0;
// 	while (i < len)
// 	{
// 		temp[i] = c;
// 		i++;
// 	}
// 	return (temp);
// }
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		while (len > 0)
		{
			str[i] = s[start];
			start++;
			i++;
			len--;
		}
		return (str);
	}
	return (NULL);
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


int		digit_count(intmax_t value, int base)
{
	int i;
	intmax_t  n;

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

char	*ft_itoa_base(intmax_t value, int base)
{
	intmax_t n;
	char *str;
	int count;

	// if (base != 10 && value < 0)
	// 	value = ~value;
	count = digit_count(value, base);
	n = value;
	str = (char *)malloc(sizeof(char) * count + 1);
	str[count] = '\0';
	if (base == 10 && value < 0)
	{
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
			str[count] = n % base + 'a' - 10;
		n = n / base;
		count--;
	}
	if (n  < 10)
		str[count] = n + '0';
	else
		str[count] = n + 'a' - 10;
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
