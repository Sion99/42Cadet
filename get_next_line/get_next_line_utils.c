/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:45:21 by sishin            #+#    #+#             */
/*   Updated: 2023/05/15 22:20:52 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	gnl_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (n + 2));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*gnl_strjoin(char *backup, char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*joined;

	joined = malloc(sizeof(char) * (gnl_strlen(backup) + gnl_strlen(buf) + 1));
	if (!joined)
	{
		free(backup);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (backup[i])
	{
		joined[i] = backup[i];
		i++;
	}
	while (buf[j])
		joined[i++] = buf[j++];
	joined[i] = 0;
	free(backup);
	return (joined);
}

char	*gnl_substr(char *s, unsigned int start)
{
	unsigned int	i;
	unsigned int	end;
	char			*sub;

	if (!s)
		return (NULL);
	end = gnl_strlen(s);
	i = 0;
	sub = malloc(sizeof(char) * (end - start + 1));
	if (!sub)
	{
		free(s);
		return (NULL);
	}
	while (++start < end)
		sub[i++] = s[start];
	free(s);
	sub[i] = 0;
	return (sub);
}
