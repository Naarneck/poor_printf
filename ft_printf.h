/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:33:32 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:33:35 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define NONE 0
# define HH 1
# define L 2
# define LL 3
# define J 4
# define Z 5
# define H 6
# define HASH 0
# define MINUS 1
# define PLUS 2
# define ZERO 3
# define SPACE 4
# define WIDTH 5
# define PREC 6
# define CAST 7

# define END 0

typedef struct	s_flags
{
	int			percent;
	int			flags[8];
	int			width;
	int			precision;
	int			cast;
	char		type;
}				t_flags;

typedef struct	s_data
{
	va_list		args;
	int			printed;
	char		*format;
	int			pos;
	t_flags		info;
	char		*arg_string;
	size_t		sym;
}				t_data;

size_t			ft_strlen(const char *s);
char			*ft_strcat(char *s1, const char *s2);
int				ft_isdigit(char c);
int				ft_atoi(const char *str);
int				digit_count(intmax_t value, int base);
char			*ft_itoa_base(intmax_t value, int base);
int				digit_count_u(uintmax_t value, int base);
char			*ft_utoa_base(uintmax_t value, int base);
void			print_char(int c, t_data *d);
void			print_string(char *str, t_data *d);
int				ft_printf(char *format, ...);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				valid_spec(t_data *t);
void			ft_swap(size_t i, size_t k, t_data *d);

void			handle_int(t_data *d);
void			handle_xou(t_data *d);
int				handle_string(t_data *d);
void			handle_percent(t_data *d);
void			handle_p(t_data *d);
int				handle_char(t_data *d);

void			handle_precision_int(t_data *d);
void			handle_hash(t_data *d);
void			handle_plus(t_data *d);
void			handle_space(t_data *d);

void			handle_width(t_data *d);

int				identify_type(t_data *d);
int				identify_other_types(t_data *d);
#endif
