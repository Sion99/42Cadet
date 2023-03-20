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

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*arr;

	i = 0;
	arr = malloc(size * count);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

#include <stdio.h>

int main()
{
	long	*array;
	long	*index;
	int		i;
	int		num;

	printf("Enter the size of the array\n");
	scanf("%i", &num);

	if ((index = array = (long *)ft_calloc(num, sizeof(long))) != NULL)
	{
		for (i = 0; i < num; ++i)
			*index++ = i;
		for (i = 0; i < num; ++i)
			printf("array[%i] = %i\n", i, array[i]);
	}
	else
	{
		perror("Out of storage");
		abort();
	}
}
