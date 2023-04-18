/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:52:38 by sishin            #+#    #+#             */
/*   Updated: 2023/04/17 21:16:47 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strcat(char *dest, char *src, ssize_t size)
{
	int				count;
	unsigned int	count_2;

	count = 0;
	count_2 = 0;
	while (dest[count])
		count++;
	while (src[count_2] && count_2 < size)
		dest[count++] = src[count_2++];
	dest[count] = '\0';
	return (dest);
}

unsigned int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strndup(char *s1, unsigned int n)
{
	char	*cpy;
	size_t	i;

	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*gnl_substr(char *s, unsigned int start)
{
	char		*sub;
	size_t		i;
	size_t		size;

	size = gnl_strlen(s);
	if (size <= start)
	{
		sub = malloc(sizeof(char) * 1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (size - start < has_newline(s))
		sub = malloc(sizeof(char) * (size - start + 1));
	else
		sub = malloc(sizeof(char) * (has_newline(s) + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < has_newline(s) && start < size)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}

char	*free_backup(char **backup)
{
	free(backup);
	backup = NULL;
	return (NULL);
}
