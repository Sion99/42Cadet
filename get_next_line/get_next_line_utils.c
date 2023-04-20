/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:52:38 by sishin            #+#    #+#             */
/*   Updated: 2023/04/20 15:54:47 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strcat(char *backup, char *buf)
{
	unsigned int	len;
	char			*cat;
	int				i;
	int				j;

	if (!backup)
		return (gnl_strndup(buf, gnl_strlen(buf)));
	i = 0;
	j = 0;
	len = gnl_strlen(backup) + gnl_strlen(buf);
	cat = (char *)malloc(sizeof(char) * len + 1);
	if (!cat)
		return (NULL);
	while (backup[i])
	{
		cat[i] = backup[i];
		i++;
	}
	while (buf[j])
		cat[i++] = buf[j++];
	cat[i] = 0;
	return (cat);
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

char	*gnl_substr(char *s, unsigned int start, unsigned int end)
{
	char			*sub;
	unsigned int	i;

	if (end <= start)
	{
		sub = malloc(sizeof(char) * 1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(sizeof(char) * (end - start + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (start < end)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}

char	*free_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
	return (NULL);
}
