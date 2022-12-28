/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:57:59 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:49:12 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_allocation_len(char const *s,
									unsigned int start,
									size_t len)
{
	size_t	tmp_len;
	int		index;
	size_t	s_len;

	tmp_len = 0;
	index = start;
	s_len = ft_strlen(s);
	while (start < s_len && s[index] != '\0' && tmp_len < len)
	{
		index++;
		tmp_len++;
	}
	return (tmp_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substring;
	size_t			s_len;

	index = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	substring = malloc((get_allocation_len(s, start, len) + 1) * sizeof(char));
	if (substring == 0)
		return (0);
	if (start < s_len)
	{
		while (s[start] != '\0' && index < len)
		{
			substring[index] = s[start];
			index++;
			start++;
		}
	}
	substring[index] = '\0';
	return (substring);
}
