/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:56:12 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 21:50:23 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_num(char const *str, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i] != '\0')
			total++;
		while ((str[i] != c && str[i] != '\0') && str[i])
			i++;
	}
	return (total);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	count;

	count = 0;
	while (src[count] && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	**free2d(char **splitted, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

char	**ft_allocate(char **splitted, char const *str, char c, int s_num)
{
	int	count;
	int	i;
	int	last;

	count = 0;
	i = 0;
	while (count < s_num && str[i])
	{
		while (str[i] == c && str[i])
			i++;
		last = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		splitted[count] = (char *)malloc(sizeof(char) * (i - last + 1));
		if (!splitted[count])
			return (free2d(splitted, count));
		ft_strncpy(splitted[count], (char *)&str[last], i - last);
		last = i;
		count++;
	}
	return (splitted);
}

char	**ft_split(char const *str, char c)
{
	char	**splitted;
	int		s_num;
	int		len;

	len = 0;
	while (str[len])
		len++;
	s_num = ft_split_num(str, c);
	splitted = (char **)malloc(sizeof(char *) * (s_num + 1));
	if (!splitted)
		return (NULL);
	splitted = ft_allocate(splitted, str, c, s_num);
	if (!splitted)
		return (NULL);
	splitted[s_num] = NULL;
	return (splitted);
}
