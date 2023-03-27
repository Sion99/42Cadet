/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:23:05 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 18:48:03 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = ft_strlen(s);
	temp = (char *)s;
	if (temp[i] == (char)c)
		return ((char *)&temp[i]);
	while (temp[--i])
	{
		if (temp[i] == (char)c)
			return ((char *)&temp[i]);
	}
	return (0);
}
/*
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = ft_strlen(s);
	temp = (char *)s;
	if (temp[i] == (char)c)
		return ((char *)&temp[i]);
	i--;
	while (i >= 0)
	{
		if (temp[i] == (char)c)
			return ((char *)&temp[i]);
		i--;
	}
	return (0);
}
*/
