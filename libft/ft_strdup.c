/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:37:41 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/17 04:43:46 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		index;
	size_t	dst_len;

	if (!s1)
		return (0);
	dst_len = ft_strlen(s1);
	dst = malloc((dst_len + 1) * sizeof(char));
	index = 0;
	if (!dst)
		return (0);
	while (s1[index] != '\0')
	{
		dst[index] = s1[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
