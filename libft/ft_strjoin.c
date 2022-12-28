/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:03:07 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:50:26 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *joined_str, char const *s1, char const *s2)
{
	size_t	s1_index;
	size_t	s2_index;
	size_t	s1_len;
	size_t	s2_len;

	s1_index = 0;
	s2_index = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (s1_index < s1_len)
	{
		joined_str[s1_index] = s1[s1_index];
		s1_index++;
	}
	while (s2_index < s2_len)
	{
		joined_str[s1_index] = s2[s2_index];
		s1_index++;
		s2_index++;
	}
	joined_str[s1_index] = '\0';
	return (joined_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined_str == 0)
		return (0);
	joined_str = join_str(joined_str, s1, s2);
	return (joined_str);
}
