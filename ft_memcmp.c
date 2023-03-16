/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:37:12 by sishin            #+#    #+#             */
/*   Updated: 2023/03/16 14:06:29 by sishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] && s2[count] && (count < n))
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
			break ;
		if (count == n - 1)
			break ;
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
