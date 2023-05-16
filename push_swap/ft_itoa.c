/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:22:29 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 21:14:33 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long long n)
{
	int	digit;

	digit = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	preprocess(int n, int *sign, long long *num)
{
	if (n < 0)
	{
		*sign = 1;
		*num = (long long)n * -1;
	}
	else
	{
		*sign = 0;
		*num = n;
	}
}

char	*ft_itoa(int n)
{
	int			sign;
	int			digit;
	char		*str;
	long long	num;

	preprocess(n, &sign, &num);
	digit = ft_check(num);
	str = (char *)malloc(sizeof(char) * (digit + sign + 1));
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[digit + sign] = '\0';
	while (1)
	{
		str[--digit + sign] = num % 10 + 48;
		num /= 10;
		if (num == 0)
			break ;
	}
	return (str);
}
