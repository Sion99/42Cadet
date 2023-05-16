/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:12 by sishin            #+#    #+#             */
/*   Updated: 2023/03/29 20:22:47 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trimmer(char const *s1, char const *set, int flag)
{
	size_t	i;

	if (flag == 0)
	{
		i = 0;
		while (i < ft_strlen(s1))
		{
			if (ft_isset(s1[i], set))
				i++;
			else
				break ;
		}
	}
	else
	{
		i = ft_strlen(s1) - 1;
		while (i >= 0)
		{
			if (ft_isset(s1[i], set))
				i--;
			else
				break ;
		}
	}
	return (i);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (src[count] && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
		dest[count++] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*trimmed;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	front = ft_trimmer(s1, set, 0);
	back = ft_trimmer(s1, set, 1);
	if (front == (size_t)ft_strlen(s1))
		return (ft_strdup(""));
	trimmed = malloc(sizeof(char) * back - front + 2);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, (char *)&s1[front], back - front + 1);
	trimmed[back - front + 1] = '\0';
	return (trimmed);
}
