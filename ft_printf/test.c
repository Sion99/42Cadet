/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:58 by sishin            #+#    #+#             */
/*   Updated: 2023/04/06 17:17:11 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int arr[5] = {0, 1234, -1234, 2147483647, -2147483648};
	char arr2[5] = {'a', '\n', '\t', '%', 'A'};
	// char *str = "Hello, World!\n";
	int a = 10;
	int hex[2] = {12, 2023};

	printf("-----------FT_PRINTF----------\n");
	for (int i = 0; i < 5; i++)
	{
		printf("---printf---\n");
		printf("%d\n", arr[i]);
		ft_printf("---ft_printf---\n");
		ft_printf("%d\n", arr[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("---printf---\n");
		printf("%c\n", arr2[i]);
		ft_printf("---ft_printf---\n");
		ft_printf("%c\n", arr2[i]);
	}
	printf("---printf---\n");
	printf("%s\n", "some string with %s hehe\n");
	ft_printf("---ft_printf---\n");
	ft_printf("%s\n", "some string with %s hehe\n");
	for (int i = 0; i < 2; i++)
	{
		printf("---printf---\n");
		printf("%x\n", hex[i]);
		ft_printf("---ft_printf---\n");
		ft_printf("%x\n", hex[i]);
	}
	printf("---printf---\n");
	printf("%p\n", &a);
	ft_printf("---ft_printf---\n");
	ft_printf("%p\n", &a);
	printf("---printf---\n");
	printf(" %s\n", "");
	ft_printf("---ft_printf---\n");
	ft_printf(" %s\n", "");
	printf("----printf----\n");
	printf("%x\n", 0);
	ft_printf("%x\n", 0);

	printf("--------------\n");
	printf("%x\n", -1);
	ft_printf("%x\n", -1);
}
