/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:31:58 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:31:59 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



#include "stdlib.h"

int digit_count(int value, int base)
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

void 	print_char(int c, t_data *d)
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

int		handle_precision(t_data *d)
{
	//if number
	if (d->format[d->pos] == '*')
	{
	}
	return (1);
}

int		handle_flags(t_data *d)
{
	if (d->format[d->pos] == '+')
	{
		d->info.flags[PLUS] = 1;
	}
	else if (d->format[d->pos] == ' ')
	{
		d->info.flags[SPACE] = 1;
	}
	if (d->format[d->pos] == '-')
	{
		d->info.flags[MINUS] = 1;
	}
	else if (d->format[d->pos] == '0')
	{
		d->info.flags[ZERO] = 1;
	}
	if (d->format[d->pos] == '#')
	{
		d->info.flags[HASH] = 1;
	}
	return (1);
}

void cast_string(int cast, t_data *d)
{
	//??????????????
}
//remember flags here
char		identify_type(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{
		/*Check for flags*/
		handle_flags(d);
		/*Check for width*/
		/*Check for precision*/
		/*Check for hh, h, l, ll, j, et z. first*/
		if (d->format[d->pos] == 'l')
			d->info.cast = L;
		else if (d->format[d->pos] == 'l' && d->format[d->pos + 1] == 'l')
			d->info.cast = LL;
		else if (d->format[d->pos] == 'h')
			d->info.cast = H;
		else if (d->format[d->pos] == 'h' && d->format[d->pos + 1] == 'h')
			d->info.cast = HH;
		else if (d->format[d->pos] == 'j')
			d->info.cast = J;
		else if (d->format[d->pos] == 'z')
			d->info.cast = Z;
		/*Then check type!*/
		if (d->format[d->pos] == 's' || d->format[d->pos] == 'S')
		{
			print_string(va_arg(d->args, char *), d);
			return (0);
		}
		else if (d->format[d->pos] == 'c' || d->format[d->pos] == 'C')
		{
			print_char(va_arg(d->args, int), d);
			return (0);
		}
		d->pos++;
	}
	return (0);
}


void	parse_format(t_data *d)
{
	while (d->format[d->pos] != '\0')
	{	
		// printf("pos: %d char %c\n", d->pos, d->format[d->pos]);
		if (d->format[d->pos] == '%')
		{
			identify_type(d);
		}
		else
		{
			print_char(d->format[d->pos], d);
		}
		d->pos++;
	}
}

//segfault if no args, and it's ok

int		ft_printf(char *format, ...)
{
	t_data	d;

	d.format = format;
	d.pos = 0;
	d.printed = 0;
	d.info.cast = 0;
	va_start(d.args, format);
	parse_format(&d);
	va_end(d.args);
	return (d.printed);
}
