/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:20:07 by izelensk          #+#    #+#             */
/*   Updated: 2017/12/09 18:20:08 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	printf("kek %d\n", 100);
	printf("kek %z\n", 100);
	printf("_____printf_end______\n");
	ft_printf("%s%S%p%d%D%i%o%O%u%U%x%X%c%C");
	return 0;
}
