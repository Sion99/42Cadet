/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:52:46 by sishin            #+#    #+#             */
/*   Updated: 2023/04/17 21:44:11 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 42

char			*get_next_line(int fd);
int				has_newline(const char *str);
char			*get_head(char **backup, char buf[]);
ssize_t			read_file(int fd, char **backup);
char			*gnl_strcat(char *dest, char *src, ssize_t size);
unsigned int	gnl_strlen(char *str);
char			*gnl_strndup(char *s1, unsigned int n);
char			*gnl_substr(char *s, unsigned int start);
char			*free_backup(char **backup);

#endif
