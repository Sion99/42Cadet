/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:04:59 by sishin            #+#    #+#             */
/*   Updated: 2023/04/03 18:00:34 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		if(ft_putchar(s[i]) == -1)
			return (-1);
		else
			i++;
	}
	return (i);
}

int	check_sign(int *n, int *check)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			*check = 0;
			return (write(1, "-2147483648", 11));
		}
		else
		{
			*n *= -1;
			*check = 1;
			return (write(1, "-", 1));
		}
	}
	else if (*n == 0)
	{
		*check = 0;
		return (write(1, "0", 1));
	}
	else
		*check = 1;
	return (0);
}

int	ft_putnbr(int n)
{
	char	str[11];
	int		count;
	int		check;
	int		i;

	i = check_sign(&n, &check);
	if (check == 1 && i != -1)
	{
		count = 0;
		while (n != 0)
		{
			str[count] = n % 10 + 48;
			count++;
			n /= 10;
		}
		count--;
		while (count >= 0)
		{
			if(ft_putchar(str[count--]) == -1)
				return (i);
			i++;
		}
	}
	return (i);
}
