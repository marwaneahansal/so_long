/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:19:30 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:22:40 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char *) s;
	while (index < n)
	{
		if ((unsigned char) str[index] == (unsigned char) c)
			return (str + index);
		index++;
	}
	return (0);
}
