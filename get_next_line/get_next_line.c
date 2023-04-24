/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:42:03 by sishin            #+#    #+#             */
/*   Updated: 2023/04/24 20:31:29 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *str)
{
	int	i;

	i = 0;
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

// backup에 개행이 있으면 있는데까지
// 없으면 backup 전부 res에 담고 리턴

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

	if (!(*backup))
		return (NULL);
	if (idx == -1)
	{
		res = gnl_strdup(*backup);
		free_backup(backup);
	}
	else
	{
		res = gnl_strndup(*backup, idx);
		*backup = gnl_substr(*backup, idx);
		if (!(*backup))
			return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	ssize_t		byte;
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			idx;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	byte = 1;
	while (byte)
	{
		printf("Hi\n");
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
		printf("backup: %s\n\n", backup);
		idx = has_newline(backup);
		printf("idx: %d\n\n", idx);
		if (idx != -1)
			return (gnl_return(&backup, idx));
	}
	return (gnl_return(&backup, idx));
}
