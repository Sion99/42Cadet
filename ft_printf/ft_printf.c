/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:40:42 by sishin            #+#    #+#             */
/*   Updated: 2023/04/06 17:25:48 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_checker(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(*ap, int)));
	else if (c == 'x')
		return (ft_putunsignedhex(0, va_arg(*ap, int)));
	else if (c == 'X')
		return (ft_putunsignedhex(1, va_arg(*ap, int)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(*ap, unsigned long)));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		temp;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			temp = printf_checker(format[++i], &ap);
		else
			temp = ft_putchar(format[i]);
		if (temp == -1)
			return (-1);
		len += temp;
		i++;
	}
	return (len);
}
