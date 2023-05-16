/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:21:26 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 17:41:35 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i])
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	if (temp[i] == (char)c)
		return (&temp[i]);
	return (0);
}
