/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:30 by sishin            #+#    #+#             */
/*   Updated: 2023/04/06 20:41:14 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			check_sign(int *n, int *check);
int			ft_putnbr(int n);
int			ft_putunsigned(unsigned int n);
char		ft_toupper(char c);
int			ft_putunsignedhex(int flag, unsigned int n);
int			ft_putaddr(unsigned long addr);

#endif
