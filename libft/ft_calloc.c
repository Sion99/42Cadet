/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:18:25 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 16:02:39 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void *ft_memset(void *s, int c, size_t len)
{
	size_t i;
	unsigned char *temp;

	i = 0;
	temp = s;
	while (i < len)
	{
		*(temp + i) = c;
		i++;
	}
	return (s);
}

void *ft_calloc(size_t count, size_t size)
{
	void *arr;

	arr = malloc(size * count);
	ft_memset(arr, 0, count * size);
	return (arr);
}

#include <stdio.h>

int main()
{
	long *array;
	long *index;
	int i;
	int num;

	printf("Enter the size of the array\n");
	scanf("%i", &num);

	if ((index = array = (long *)ft_calloc(num, sizeof(long))) != NULL)
	{
		for (i = 0; i < num; ++i)
			printf("array[%i] = %li\n", i, array[i]);
	}
	else
	{
		perror("Out of storage");
		abort();
	}
}
