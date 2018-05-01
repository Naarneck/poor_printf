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
	int ret;
	int ret_my;

	// printf("%.s\n", "string");
	// printf("%.3s\n", "string");
	// printf("%.5s\n", "string");
	// printf("%.10s\n", "string");
	
	printf("%s\n", "string");
	printf("%-3s\n", "string");
	printf("%5s\n", "string");
	printf("%10s\n", "string");
	
	// printf("%-d\n", 12);
	// printf("%+d\n", 12);
	// printf("%#d\n", 12);
	// printf("%0d\n", 12);
	// printf("% d\n", 12);


	// printf("i: %i\n", -999);
	// printf("li: %li\n", -999);
	// printf("lli: %lzi\n", -999);
	// printf("zi: %zi\n", -999);
	// printf("lzi: %lzi\n", -999);
	// printf("hhi: %hhi\n", -999);
	// printf("hi: %hi\n", -999);
	// printf("zli: %zli\n", -999);
	printf("_____printf_end______\n");
	// ft_printf("%s%S%p%d%D%i%o%O%u%U%x%X%c%C", "123");
	// ret_my = ft_printf("ololo: %c%c%c%s\n",'K','E','K',"ssoso");
	// ret =	    printf("ololo: %c%c%c%s\n",'K','E','K',"ssoso");
	// printf("ret_my= %d ret= %d\n",ret_my, ret );

	ret_my = ft_printf("orroo: %-5.3hhs + % 5.3hhs\n","such","test");
	ret =	    printf("orroo: %-5.3hhs + % 5.3hhs\n","such","test");
	printf("ret_my= %d ret= %d\n",ret_my, ret );

	return 0;
}


