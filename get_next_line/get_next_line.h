/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:43:52 by sishin            #+#    #+#             */
/*   Updated: 2023/04/24 20:30:54 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*gnl_return(char **backup, int idx);
char			*gnl_strndup(char *str, int n);
char			*gnl_strdup(char *str);
char			*gnl_strjoin(char *backup, char *buf);
char			*gnl_substr(char *s, unsigned int start);
char			*free_backup(char **backup);
unsigned int	gnl_strlen(char *s);
int				has_newline(char *str);

#endif
