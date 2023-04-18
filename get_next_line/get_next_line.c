/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:52:31 by sishin            #+#    #+#             */
/*   Updated: 2023/04/17 22:19:15 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// checks if there is '\n', returns the index of '\n', -1 if found nothing.
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

// returns the string before '\n'.
/*char	*get_head(char **res)
{
	int		i;
	int		j;
	char	*head;

	i = has_newline(*res);
	head = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		head[j] = *res[j];
		j++;
	}
	head[j] = '\0';
	return (head);
}
*/

char	*get_head(char **backup, char buf[])
{
	char	*res;

	if (has_newline(buf) < 0)
	{
		res = gnl_strndup(buf, gnl_strlen(buf));
	}
	else
	{
		res = gnl_strndup(buf, has_newline(buf));
	}
	return (res);
}

ssize_t	read_file(int fd, char **backup);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	ssize_t		len;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (free_backup(backup));
		if (!len)
			break ;
		buf[BUFFER_SIZE] = 0;
		res = get_head(&backup, buf);
	}
	return (res);
}
