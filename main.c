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

	   printf("%.s\n", "string");
	ft_printf("%.s\n", "string");
	   printf("%.3s\n", "string");
	ft_printf("%.3s\n", "string");
	   printf("%.5s\n", "string");
	ft_printf("%.5s\n", "string");
	   printf("%.10s\n", "string");
	ft_printf("%.10s\n", "string");
	
	   printf("%s\n", "string");
	ft_printf("%s\n", "string");
	   printf("%-3s\n", "string");
	ft_printf("%-3s\n", "string");
	   printf("%5s\n", "string");
	ft_printf("%5s\n", "string");
	   printf("%10s\n", "string");
	ft_printf("%10s\n", "string");

	   printf("%-5d\n", 12);
	ft_printf("%-5d\n", 12);
	   printf("%+5d\n", 12);
	ft_printf("%+5d\n", 12);
	   printf("%#5d\n", 12);
	ft_printf("%#5d\n", 12);
	   printf("%05d\n", 12);
	ft_printf("%05d\n", 12);
	   printf("% 5d\n", 12);
	ft_printf("% 5d\n", 12);

	   printf("%-5d\n", -12);
	ft_printf("%-5d\n", -12);
	   printf("%+5d\n", -12);
	ft_printf("%+5d\n", -12);
	   printf("%#5d\n", -12);
	ft_printf("%#5d\n", -12);
	   printf("%05d\n", -12);
	ft_printf("%05d\n", -12);
	   printf("% 5d\n", -12);
	ft_printf("% 5d\n", -12);

	   printf("%010d e\n", -12);
	ft_printf("%010d e\n", -12);
	   printf("%010d d\n", -12);
	ft_printf("%010d d\n", -12);
	   printf("%010d c\n", -12);
	ft_printf("%010d c\n", -12);
	   printf("%-010d b\n", -12);
	ft_printf("%-010d b\n", -12);
	   printf("%-10d a\n", -12);
	ft_printf("%-10d a\n", -12);
	
printf("i__________________________\n");
	   printf("i: %i\n", 999);
	ft_printf("i: %i\n", 999);
	   printf("li: %li\n", 999);
	ft_printf("li: %li\n", 999);
	   printf("lli: %lli\n", 999);
	ft_printf("lli: %lli\n", 999);
	   printf("zi: %zi\n", 999);
	ft_printf("zi: %zi\n", 999);
	   printf("hhi: %hhi\n", 999);
	ft_printf("hhi: %hhi\n", 999);
	   printf("hi: %hi\n", 999);
	ft_printf("hi: %hi\n", 999);
printf("u__________________________\n");
	   printf("u: %u\n", 999);
	ft_printf("u: %u\n", 999);
	   printf("lu: %lu\n", 999);
	ft_printf("lu: %lu\n", 999);
	   printf("llu: %lu\n", 999);
	ft_printf("llu: %lu\n", 999);
	   printf("zu: %zu\n", 999);
	ft_printf("zu: %zu\n", 999);
	   printf("hhu: %hu\n", 999);
	ft_printf("hhu: %hu\n", 999);
	   printf("hu: %hu\n", 999);
	ft_printf("hu: %hu\n", 999);
printf("o__________________________\n");
	   printf("o: %o\n", 999);
	ft_printf("o: %o\n", 999);
	   printf("lo: %lo\n", 999);
	ft_printf("lo: %lo\n", 999);
	   printf("llo: %llo\n", 999);
	ft_printf("llo: %llo\n", 999);
	   printf("zo: %zo\n", 999);
	ft_printf("zo: %zo\n", 999);
	   printf("hho: %hho\n", 999);
	ft_printf("hho: %hho\n", 999);
	   printf("ho: %ho\n", 999);
	ft_printf("ho: %ho\n", 999);
printf("x__________________________\n");
	   printf("x: %x\n", 999);
	ft_printf("x: %x\n", 999);
	   printf("lx: %lx\n", 999);
	ft_printf("lx: %lx\n", 999);
	   printf("llx: %llx\n", 999);
	ft_printf("llx: %llx\n", 999);
	   printf("zx: %zx\n", 999);
	ft_printf("zx: %zx\n", 999);
	   printf("hhx: %hhx\n", 999);
	ft_printf("hhx: %hhx\n", 999);
	   printf("hx: %hx\n", 999);
	ft_printf("hx: %hx\n", 999);
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


