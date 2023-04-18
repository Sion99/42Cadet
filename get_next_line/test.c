/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:23:22 by sishin            #+#    #+#             */
/*   Updated: 2023/04/15 16:59:57 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define BUFFER 1024

int main()
{
	char	buf[BUFFER];
	int		flag;

	flag = read(0, buf, BUFFER);
	printf("%s", buf);
	printf("%d\n", flag);
}
