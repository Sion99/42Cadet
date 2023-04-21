/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:33:46 by sishin            #+#    #+#             */
/*   Updated: 2023/04/20 20:57:06 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 개행이 있는지 판별
int	has_newline(const char *str)
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

// 개행까지 문자열을 떼어 res에 넣고, 나머지는 앞으로 당겨옴.
char	*get_head(char **backup)
{
	char			*res;
	int				end;

	end = has_newline(*backup);
	if (end == -1)
	{
		res = gnl_strndup(*backup, gnl_strlen(*backup));
		free_backup(backup);
	}
	else
	{
		res = gnl_substr(*backup, 0, end);
		*backup = gnl_substr(*backup, end + 1, gnl_strlen(*backup) - 1);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (free_backup(&backup));
		if (!len)
			break ;
		buf[len] = 0;
		backup = gnl_strcat(backup, buf);
		if (has_newline(backup) != -1)
		{
			return (get_head(&backup));
		}
	}
	return (get_head(&backup));
}
