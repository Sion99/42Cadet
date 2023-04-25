/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:42:03 by sishin            #+#    #+#             */
/*   Updated: 2023/04/25 13:58:30 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*free_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
	return (NULL);
}

char	*gnl_strdup(char	*str)
{
	char			*dup;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = gnl_strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*gnl_return(char	**backup, int idx)
{
	char	*res;

	if (!(*backup) || idx == -2)
		return (NULL);
	if (!**backup)
		return (free_backup(backup));
	if (idx == -1)
	{
		res = gnl_strdup(*backup);
		free_backup(backup);
	}
	else
	{
		res = gnl_strndup(*backup, idx);
		if (!res)
			return (free_backup(backup));
		*backup = gnl_substr(*backup, idx);
		if (!(*backup))
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	ssize_t		byte;
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (free_backup(&backup));
		if (!byte)
			break ;
		buf[byte] = 0;
		if (!backup)
			backup = gnl_strdup(buf);
		else
			backup = gnl_strjoin(backup, buf);
		if (!backup)
			return (NULL);
		if (has_newline(backup) != -1)
			return (gnl_return(&backup, has_newline(backup)));
	}
	return (gnl_return(&backup, has_newline(backup)));
}
