/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:01:53 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:25:24 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;
	char	*str1;
	char	*str2;

	index = 0;
	str1 = (char *) s1;
	str2 = (char *) s2;
	while (index < n)
	{
		if ((unsigned char) str1[index] > (unsigned char) str2[index])
			return ((unsigned char) str1[index] - (unsigned char) str2[index]);
		else if ((unsigned char) str1[index] < (unsigned char) str2[index])
			return ((unsigned char) str1[index] - (unsigned char) str2[index]);
		index++;
	}
	return (0);
}
