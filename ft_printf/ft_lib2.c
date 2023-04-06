/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:30 by sishin            #+#    #+#             */
/*   Updated: 2023/04/06 17:20:24 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int	check_sign2(int n, long long *num)
{
	if (n < 0)
	{
		*num = (long long)-n;
		return (write(1, "-", 1));
	}
	else if (n == 0)
	{
		*num = 0;
		return (write(1, "0", 1));
	}
	else
		*num = (long long)n;
	return (0);
}
*/
/*
int	ft_puthex(int flag, int n)
{
	int			i;
	int			count;
	long long	num;
	char		str[11];
	char		*x;

	x = "0123456789abcdef";
	i = check_sign2(n, &num);
	count = 0;
	while (num != 0)
	{
		str[count++] = x[num % 16];
		if (flag == 1)
			str[count - 1] = ft_toupper(str[count - 1]);
		num /= 16;
	}
	count--;
	while (count >= 0)
	{
		if (ft_putchar(str[count--]) == -1)
			return (i);
		i++;
	}
	return (i);
}
*/

int	ft_putunsignedhex(int flag, unsigned int n)
{
	int		i;
	int		count;
	char	str[20];
	char	*x;

	x = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	count = 0;
	while (n != 0)
	{
		str[count++] = x[n % 16];
		if (flag == 1)
			str[count - 1] = ft_toupper(str[count - 1]);
		n /= 16;
	}
	while (--count >= 0)
	{
		if (ft_putchar(str[count]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putaddr(unsigned long addr)
{
	int		i;
	int		count;
	char	str[20];
	char	*x;

	i = ft_putstr("0x");
	if (i == -1)
		return (i);
	x = "0123456789abcdef";
	if (addr == 0)
		return (i + ft_putchar('0'));
	count = 0;
	while (addr != 0)
	{
		str[count++] = x[addr % 16];
		addr /= 16;
	}
	while (--count >= 0)
	{
		if (ft_putchar(str[count]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
