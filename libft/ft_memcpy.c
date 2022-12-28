/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:53:41 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:01:47 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	len;
	char	*char_dst;
	char	*char_src;

	if (src == 0 && dst == 0)
		return (0);
	char_dst = (char *) dst;
	char_src = (char *) src;
	len = 0;
	while (len < n)
	{
		char_dst[len] = char_src[len];
		len++;
	}
	return (dst);
}
