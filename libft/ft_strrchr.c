/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:23:05 by sishin            #+#    #+#             */
/*   Updated: 2023/03/27 22:14:11 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return (temp + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (temp + i);
		i--;
	}
	return (0);
}
