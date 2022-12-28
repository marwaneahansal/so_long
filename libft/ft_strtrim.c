/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:49:38 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:51:08 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set_char(char const *set, char c)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (-1);
}

static int	get_char_count(char const *s1, char const *set, int s1_len)
{
	int	index;
	int	char_count;

	index = 0;
	char_count = 0;
	if (s1_len == -1)
	{
		while (s1[index] != '\0' && check_set_char(set, s1[index]) == 1)
		{
			char_count++;
			index++;
		}
	}
	else
	{
		index = ft_strlen(s1) - 1;
		while (s1[index] != '\0' && check_set_char(set, s1[index]) == 1)
		{
			char_count++;
			index--;
		}
	}
	return (char_count);
}

static int	get_str_size(int s1_len, int start_char_count, int end_char_count)
{
	int	str_size;

	str_size = 0;
	if (s1_len - (start_char_count + end_char_count) < -1)
		str_size = 1;
	else
		str_size = s1_len - (start_char_count + end_char_count);
	return (str_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		start_char_count;
	int		end_char_count;
	int		s1_len;
	char	*trimmed_str;

	if (s1 == 0 || set == 0)
		return (0);
	s1_len = ft_strlen(s1);
	start_char_count = get_char_count(s1, set, -1);
	end_char_count = get_char_count(s1, set, s1_len);
	index = get_str_size(s1_len, start_char_count, end_char_count);
	trimmed_str = malloc((index + 1) * sizeof(char));
	if (trimmed_str == 0)
		return (0);
	index = 0;
	while (start_char_count < (s1_len - end_char_count))
	{
		trimmed_str[index] = s1[start_char_count];
		index++;
		start_char_count++;
	}
	trimmed_str[index] = '\0';
	return (trimmed_str);
}
