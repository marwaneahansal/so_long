/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:02:56 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:14:04 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_index;
	size_t	dst_index;
	size_t	dst_len;
	size_t	src_len;

	src_index = 0;
	src_len = ft_strlen(src);
	if (dst == 0 && dstsize == 0)
		return (src_len + dstsize);
	dst_len = ft_strlen(dst);
	dst_index = dst_len;
	if (dstsize > dst_len)
	{
		while (src[src_index] != '\0' && src_index < dstsize - dst_len - 1)
		{
			dst[dst_index] = src[src_index];
			src_index++;
			dst_index++;
		}
		dst[dst_index] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + dstsize);
}
