/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:30:05 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 21:34:01 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_sign(int *n, int *check, int fd)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			*check = 0;
		}
		else
		{
			write(fd, "-", 1);
			*n *= -1;
			*check = 1;
		}
	}
	else if (*n == 0)
	{
		write(fd, "0", 1);
		*check = 0;
	}
	else
		*check = 1;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		count;
	int		check;

	check_sign(&n, &check, fd);
	if (check == 1)
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
			write(fd, &str[count], 1);
			count--;
		}
	}
}
