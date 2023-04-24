/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:31:47 by sishin            #+#    #+#             */
/*   Updated: 2023/04/24 20:31:48 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	// int fd1;
	// printf("***EMPTY TEXT***\n");
	// fd1 = open("./empty.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd1));
	// printf("%s\n", get_next_line(fd1));
	
	// int fd2;
	// printf("***1CHAR TEXT***\n");
	// fd2 = open("./1char.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd2));
	// printf("%s\n", get_next_line(fd2));
	// printf("%s\n", get_next_line(fd2));

	// int fd3;
	// printf("***ONE_LINE_NO_NL TEXT***\n");
	// fd3 = open("./one_line_no_nl.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd3));
	// printf("%s\n", get_next_line(fd3));
	// printf("%s\n", get_next_line(fd3));

	// int fd4;
	// printf("***ONE_LINE TEXT***\n");
	// fd4 = open("./one_line.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd4));
	// printf("%s\n", get_next_line(fd4));
	// printf("%s\n", get_next_line(fd4));

	// int fd5;
	// printf("***ONLY_NL TEXT***\n");
	// fd5 = open("./only_nl.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));
	// printf("%s\n", get_next_line(fd5));

	int fd6;
	printf("***MANY_LINES TEXT***\n");
	fd6 = open("./many_lines.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));
	printf("%s\n", get_next_line(fd6));

}
