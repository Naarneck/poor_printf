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
	printf("%.3s\n", "string");
	printf("%.5s\n", "string");
	printf("%.10s\n", "string");
	printf("%-6d\n", -10000);
	printf("%+# 0-6d\n", 10);
	printf("_____printf_end______\n");
	// ft_printf("%s%S%p%d%D%i%o%O%u%U%x%X%c%C", "123");
	ret_my = ft_printf("sdasdldsa\n");
	ret = printf("sdasdldsa\n");
	printf("ret_my= %d ret= %d\n",ret_my, ret );
	return 0;
}


