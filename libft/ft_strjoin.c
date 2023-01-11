/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:39:18 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/11 03:27:05 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_str(char *joined_str, char *s1, char *s2)
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

	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined_str)
	{
		free((char *) s1);
		return (0);
	}
	joined_str = join_str(joined_str, (char *) s1, (char *) s2);
	free((char *) s1);
	return (joined_str);
}
