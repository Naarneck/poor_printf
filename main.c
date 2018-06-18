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
#include <wchar.h>
#include <limits.h>

#define VAL LONG_MAX
#define VAL 0

int main(int argc, char const *argv[])
{
	int ret;
	int ret_my;
	char *str = "18446744069414584320";

	ret = 0;
	ret_my = 0;
	   printf("kek .%+-15d. kek\n", VAL);
	ft_printf("kek .%+-15d. kek\n", VAL);
	   printf("kek .%++15d. kek\n", VAL);
	ft_printf("kek .%++15d. kek\n", VAL);
	   printf("kek .%+#15d. kek\n", VAL);
	ft_printf("kek .%+#15d. kek\n", VAL);
	   printf("kek .%+015d. kek\n", VAL);
	ft_printf("kek .%+015d. kek\n", VAL);
	   printf("kek .%+ 15d. kek\n", VAL);
	ft_printf("kek .%+ 15d. kek\n", VAL);

	   printf("Kek .%+-15d.  kek\n", VAL);
	ft_printf("Kek .%+-15d.  kek\n", VAL);
	   printf("Kek .%++15d.  kek\n", VAL);
	ft_printf("Kek .%++15d.  kek\n", VAL);
	   printf("Kek .%+#15d.  kek\n", VAL);
	ft_printf("Kek .%+#15d.  kek\n", VAL);
	   printf("Kek .%+015d.  kek\n", VAL);
	ft_printf("Kek .%+015d.  kek\n", VAL);
	   printf("Kek .%+      15d.  kek\n", VAL);
	ft_printf("Kek .%+      15d.  kek\n", VAL);
	   printf("Kek .% d.  kek\n", VAL);
	ft_printf("Kek .% d.  kek\n", VAL);	
	  printf("Kek .%0-d.  kek\n", VAL);
	ft_printf("Kek .%0-d.  kek\n", VAL);	

printf("D__________________________\n");
	   printf("%-5D\n", VAL);
	ft_printf("%-5D\n", VAL);
	   printf("%+5D\n", VAL);
	ft_printf("%+5D\n", VAL);
	   printf("%#5D\n", VAL);
	ft_printf("%#5D\n", VAL);
	   printf("%05D\n", VAL);
	ft_printf("%05D\n", VAL);
	   printf("% 5D\n", VAL);
	ft_printf("% 5D\n", VAL);

	   printf("%010D e\n", VAL);
	ft_printf("%010D e\n", VAL);
	   printf("%010D d\n", VAL);
	ft_printf("%010D d\n", VAL);
	   printf("%010D c\n", VAL);
	ft_printf("%010D c\n", VAL);
	   printf("%-010D b\n", VAL);
	ft_printf("%-010D b\n", VAL);
	   printf("%-10D a\n", VAL);
	ft_printf("%-10D a\n", VAL);
	   printf("{%5p}\n", 0);
	ft_printf("{%5p}\n", 0);
printf("%%__________________________\n");
	   printf("%   %\n", str);
	ft_printf("%   %\n", str);
	   printf(".%3%.\n", str);
	ft_printf(".%3%.\n", str);
	   printf(".%5%.\n", str);
	ft_printf(".%5%.\n", str);
	   printf(".%-10%.\n", str);
	ft_printf(".%-10%.\n", str);
printf("p__________________________\n");
	   printf("u: %p\n", str);
	ft_printf("u: %p\n", str);
	   printf("lu: %lp\n", str);
	ft_printf("lu: %lp\n", str);
	   printf("llu: %lp\n", str);
	ft_printf("llu: %lp\n", str);
	   printf("zu: %zp\n", str);
	ft_printf("zu: %zp\n", str);
	   printf("hhu: %hp\n", str);
	ft_printf("hhu: %hp\n", str);
	   printf("hu: %hp\n", str);
	ft_printf("hu: %hp\n", str);
printf("s__________________________\n");
	   printf(".%.s.\n", str);
	ft_printf(".%.s.\n", str);
	   printf(".%.3s.\n", str);
	ft_printf(".%.3s.\n", str);
	   printf(".%.5s.\n", str);
	ft_printf(".%.5s.\n", str);
	   printf(".%.20s.\n", NULL);
	ft_printf(".%.20s.\n", NULL);
	//    printf("%S", L"Á±≥\n");
	// ft_printf("%S", L"Á±≥\n");
	   printf("++++%s++++\n", "astring");
	ft_printf("++++%s++++\n", "astring");
	   printf("---%-3s---\n", "string");
	ft_printf("---%-3s---\n", "string");
	   printf("aaa%+2.0saaa.\n", "string");
	ft_printf("aaa%+2.0saaa.\n", "string");
	   printf("%10s .a\n", "string");
	ft_printf("%10s .a\n", "string");

printf("i__________________________\n");
	   printf("i: %i\n", VAL);
	ft_printf("i: %i\n", VAL);
	   printf("li: %li\n", VAL);
	ft_printf("li: %li\n", VAL);
	   printf("lli: %lli\n", VAL);
	ft_printf("lli: %lli\n", VAL);
	   printf("zi: %zi\n", VAL);
	ft_printf("zi: %zi\n", VAL);
	   printf("hhi: %hhi\n", VAL);
	ft_printf("hhi: %hhi\n", VAL);
	   printf("hi: %hi\n", VAL);
	ft_printf("hi: %hi\n", VAL);
	   printf("++ @d%++ d\n", 11);
	ft_printf("++ @d%++ d\n", 11);
	   printf("%0+5d\n", -42);
	ft_printf("%0+5d\n", -42);
	   printf("%0+5d\n", 42);
	ft_printf("%0+5d\n", 42);
	   printf("prec0: .%5.d %5.0d.\n", 303, 0);
	ft_printf("prec0: .%5.d %5.0d.\n", 303, 0);
printf("u__________________________\n");
	   printf("u: %u\n", VAL);
	ft_printf("u: %u\n", VAL);
	   printf("lu: %lu\n", VAL);
	ft_printf("lu: %lu\n", VAL);
	   printf("llu: %lu\n", VAL);
	ft_printf("llu: %lu\n", VAL);
	   printf("zu: %zu\n", VAL);
	ft_printf("zu: %zu\n", VAL);
	   printf("hhu: %hu\n", VAL);
	ft_printf("hhu: %hu\n", VAL);
	   printf("hu: %hu\n", VAL);
	ft_printf("hu: %hu\n", VAL);
	   printf("_u: % u\n", 4294967295);
	ft_printf("_u: % u\n", 4294967295);
	   printf("+u: %+u\n", 4294967295);
	ft_printf("+u: %+u\n", 4294967295);
	   printf("%hU\n", 4294967296);
	ft_printf("%hU\n", 4294967296);
	   printf("%U\n", 4294967296);
	ft_printf("%U\n", 4294967296);

printf("o__________________________\n");
	   printf("5x:%#08o\n", 42);
	ft_printf("5x:%#08o\n", 42);
	   printf("1x:%#01o\n", 42);
	ft_printf("1x:%#01o\n", 42);
	   printf("2x:%#02o\n", 42);
	ft_printf("2x:%#02o\n", 42);
	   printf("3x:%#03o\n", 42);
	ft_printf("3x:%#03o\n", 42);	   
	   printf("o: %o\n", VAL);
	ft_printf("o: %o\n", VAL);
	   printf("lo: %lo\n", VAL);
	ft_printf("lo: %lo\n", VAL);
	   printf("llo: %llo\n", VAL);
	ft_printf("llo: %llo\n", VAL);
	   printf("zo: %zo\n", VAL);
	ft_printf("zo: %zo\n", VAL);
	   printf("hho: %hho\n", VAL);
	ft_printf("hho: %hho\n", VAL);
	   printf("ho: %ho\n", VAL);
	ft_printf("ho: %ho\n", VAL);
	   printf("#o O: .%#o.\n", 0);
	ft_printf("#o O: .%#o.\n", 0);
	   printf("#o _O: .%# o.\n", 0);
	ft_printf("#o _O: .%# o.\n", 0);
	   printf("x %.4x, %x\n", 0, 0);
	ft_printf("x %.4x, %x\n", 0, 0);
	   printf("p %.4p, %.4p\n", 0, 42);
	ft_printf("p %.4p, %.4p\n", 0, 42);
	   printf("p %9.2p, %.0p\n", 1234, 0);
	ft_printf("p %9.2p, %.0p\n", 1234, 0);
printf("x__________________________\n");
	   printf("{%030x}\n", 0xFFFF);
	ft_printf("{%030x}\n", 0xFFFF);
	   printf("1x:%#01x\n", 42);
	ft_printf("1x:%#01x\n", 42);
	   printf("2x:%#02x\n", 42);
	ft_printf("2x:%#02x\n", 42);
	   printf("3x:%#03x\n", 42);
	ft_printf("3x:%#03x\n", 42);
	   printf("lx: %#10lx\n", VAL);
	ft_printf("lx: %#10lx\n", VAL);
	   printf("llx: %#10llx\n", VAL);
	ft_printf("llx: %#10llx\n", VAL);
	   printf("zx: %#10zx\n", VAL);
	ft_printf("zx: %#10zx\n", VAL);
	   printf("hhx: %#10hhx\n", VAL);
	ft_printf("hhx: %#10hhx\n", VAL);
	   printf("hx: %#10hx\n", VAL);
	ft_printf("hx: %#10hx\n", VAL);
	   printf("jx: %#10jx\n", VAL);
	ft_printf("jx: %#10jx\n", VAL);
	   printf("prec0: .%5.x %5.0x.\n", 303, 0);
	ft_printf("prec0: .%5.x %5.0x.\n", 303, 0);
printf("X__________________________\n");
	   printf("X: %#10X\n", VAL);
	ft_printf("X: %#10X\n", VAL);
	   printf("lX: %#10lX\n", VAL);
	ft_printf("lX: %#10lX\n", VAL);
	   printf("llX: %#10llX\n", VAL);
	ft_printf("llx: %#10llX\n", VAL);
	   printf("hhX: %#10hhX\n", VAL);
	ft_printf("hhX: %#10hhX\n", VAL);
	   printf("hX: %#10hX\n", VAL);
	ft_printf("hX: %#10hX\n", VAL);
	   printf("zX: %#10zX\n", VAL);
	ft_printf("zX: %#10zX\n", VAL);
	   printf("jx: %#10jX\n", VAL);
	ft_printf("jx: %#10jX\n", VAL);	
printf(".p-__________________________\n");
	   printf("%4.15d\n",-42);
	ft_printf("%4.15d\n",-42);
	   printf("%-+10.5d\n",-4242);
	ft_printf("%-+10.5d\n",-4242);
	   printf("%10.20d\n",-42);
	ft_printf("%10.20d\n",-42);
	   printf("%-10.5d\n",-4242);
	ft_printf("%-10.5d\n",-4242);
	   printf("%+4.1d\n",-42);
	ft_printf("%+4.1d\n",-42);
	   printf("%.5d\n",-4242);
	ft_printf("%.5d\n",-4242);
printf(".p+__________________________\n");
	   printf("%#4.15x\n",42);
	ft_printf("%#4.15x\n",42);
	   printf("%-+10.5x\n",4242);
	ft_printf("%-+10.5x\n",4242);
	   printf("%10.20x\n",42);
	ft_printf("%10.20x\n",42);
	   printf("%-10.5x\n",4242);
	ft_printf("%-10.5x\n",4242);
	   printf("%+4.1x\n",42);
	ft_printf("%+4.1x\n",42);
	   printf("%03.2d\n", 1);
	ft_printf("%03.2d\n", 1);
printf(".c__________________________\n");
	   printf("%#4.15c\n",'a');
	ft_printf("%#4.15c\n",'a');
	   printf("%-+10.5c\n",'a');
	ft_printf("%-+10.5c\n",'a');
	   printf("%10.20c\n",'a');
	ft_printf("%10.20c\n",'a');
	   printf("%-10.5c\n",'a');
	ft_printf("%-10.5c\n",'a');
	   printf("%+4.1c\n",'a');
	ft_printf("%+4.1c\n",'a');
	   printf(".%.2c.\n", 1);
	ft_printf(".%.2c.\n", 1);	
	   printf(".%.2c.\n", 1);
	ft_printf(".%.2c.\n", 1);	
	   printf(".%.2c.\n", 1);
	ft_printf(".%.2c.\n", 1);	
	   printf("% Zoooo\n");
	ft_printf("% Zoooo\n");
	ret =       printf("@moulitest: .%c.\n", 0);
	ret_my = ft_printf("@MYulitest: .%c.\n", 0);
	printf("ret_my= %d ret= %d\n",ret_my, ret );
	ret =       printf("@moulitest: .%0c.\n", 0);
	ret_my = ft_printf("@MYulitest: .%0c.\n", 0);
	printf("ret_my= %d ret= %d\n",ret_my, ret );
	ret =       printf("@moulitest: .%1c.\n", 0);
	ret_my = ft_printf("@MYulitest: .%1c.\n", 0);
	printf("ret_my= %d ret= %d\n",ret_my, ret );
	ret =       printf("@moulitest: .%2c.\n", 0);
	ret_my = ft_printf("@MYulitest: .%2c.\n", 0);
	printf("ret_my= %d ret= %d\n",ret_my, ret );
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


