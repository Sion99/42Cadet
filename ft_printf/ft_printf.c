/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:40:42 by sishin            #+#    #+#             */
/*   Updated: 2023/04/06 13:02:19 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_checker(const char *format, va_list *ap)
{
	int	i;
	int	len;
	int	checker;
	int	num;
	char c;
	char *temp;

	i = 0;
	len = 0;
	if (format[i + 1] == 'c')
	{
		c = va_arg(*ap, int);
		checker = ft_putchar(c);
		if (checker != -1)
			len += checker;
		else
			return (-1);
	}
	else if (format[i + 1] == 's')
	{
		temp = va_arg(*ap, char *);
		checker = ft_putstr(temp);
		if (checker != -1)
			len += checker;
		else
			return (-1);
	}
	else if (format[i + 1] == 'd' || format[i + 1] == 'u')
	{
		num = va_arg(*ap, int);
		checker = ft_putnbr(num);
		if (checker != -1)
			len += checker;
		else
			return (-1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += printf_checker(&format[i], &ap);
			i++;
		}
		else
		{
			len++;
			write(1, &format[i], 1);
		}
		i++;
	}
	return (len);
}

int main()
{
	int a, b, c, d;
	a = ft_printf("hello, world!\n");
	b = ft_printf("%s, worl%c!\n", "hello", 'd');
	c = ft_printf("%s\n", "");
	d = ft_printf("answer : %d\n", -1234);

	ft_printf("a : %d, b : %d, c : %d, d : %d\n", a, b, c, d);
}
