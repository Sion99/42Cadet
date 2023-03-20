/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:06:23 by sishin            #+#    #+#             */
/*   Updated: 2023/03/20 17:10:11 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while ((s1[count] && s2[count]))
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
			break ;
		if (count == (n - 1))
			break ;
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
