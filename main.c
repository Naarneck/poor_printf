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
	
	// printf("%s\n", "string");
	// printf("%-3s\n", "string");
	// printf("%5s\n", "string");
	// printf("%10s\n", "string");
	
	// printf("%-5d\n", 12);
	// printf("%+5d\n", 12);
	// printf("%#5d\n", 12);
	// printf("%05d\n", 12);
	// printf("% 5d\n", 12);

	// printf("%-5d\n", -12);
	// printf("%+5d\n", -12);
	// printf("%#5d\n", -12);
	// printf("%05d\n", -12);
	// printf("% 5d\n", -12);

	// printf("%010d\n", -12);
	// printf("%010d\n", -12);
	// printf("%010d\n", -12);
	// printf("%-010d\n", -12);
	// printf("%-10d\n", -12);

	   printf("i: %i\n", -999);
	ft_printf("i: %i\n", -999);
	   printf("li: %li\n", -999);
	ft_printf("li: %li\n", -999);
	   printf("lli: %lli\n", -999);
	ft_printf("lli: %lli\n", -999);
	   printf("zi: %zi\n", -999);
	ft_printf("zi: %zi\n", -999);
	   printf("hhi: %hhi\n", -999);
	ft_printf("hhi: %hhi\n", -999);
	   printf("hi: %hi\n", -999);
	ft_printf("hi: %hi\n", -999);
	
	//    printf("zli: %zli\n", -999);
	// ft_printf("zli: %zli\n", -999);
	printf("_____printf_end______\n");
	// ft_printf("%s%S%p%d%D%i%o%O%u%U%x%X%c%C", "123");
	// ret_my = ft_printf("ololo: %c%c%c%s\n",'K','E','K',"ssoso");
	// ret =	    printf("ololo: %c%c%c%s\n",'K','E','K',"ssoso");

	// ret_my = ft_printf("mhm: %d%D%i\n",-1,990, 1010);
	// ret =	    printf("mhm: %d%D%i\n",-1,990, 1010);

	// ret_my = ft_printf("mhm: %10d\n",12312);
	// ret =	    printf("mhm: %10d\n",12312);
	// ret_my = ft_printf("mhm: %016d\n",12312);
	// ret =	    printf("mhm: %016d\n",12312);
	// ret_my = ft_printf("orroo: %-509.389hhs + % 500.388hhs\n","such","test");
	// ret =	    printf("orroo: %-509.389hhs + % 500.388hhs\n","such","test");
	printf("ret_my= %d ret= %d\n",ret_my, ret );

	return 0;
}


