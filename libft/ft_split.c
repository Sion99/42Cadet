/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:56:12 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 19:49:41 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splittednum(char const *s, char c)
{
	size_t	i;
	size_t	len;
	int		snum;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if(s[i] == c)
			snum++;
		i++;
	}
	return (snum + 1);
}

char	**free2d(char **s, int range)
{
	int	i;

	i = 0;
	while (i < range)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		snum;
	char	**splitted;

	snum = ft_splittednum(s, c);
	splitted = (char **)malloc(sizeof(char *) * (snum + 1));
	if (!splitted)
		return(0);
}
