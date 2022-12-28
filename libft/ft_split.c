/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:58:19 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:53:11 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(char const *s, char c)
{
	size_t	s_len;
	char	*word;
	size_t	index;

	s_len = 0;
	index = 0;
	while (s[s_len] != '\0' && s[s_len] != c)
		s_len++;
	word = malloc(((s_len + 1) * sizeof(char)));
	if (word == 0)
		return (0);
	while (index < s_len)
	{
		word[index] = s[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

static void	free_strs(char **str, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		free(str[index]);
		index++;
	}
	free(str);
}

static char	**fill_str(char const *s, char c, char **str, size_t word_count)
{
	size_t	index;
	size_t	str_index;

	index = 0;
	str_index = 0;
	while (s[index] != '\0' && str_index < word_count)
	{
		while (s[index] != '\0' && s[index] == c)
			index++;
		if (s[index] != '\0')
		{
			str[str_index] = get_word(s + index, c);
			if (!str[str_index])
			{
				free_strs(str, str_index);
				return (0);
			}
			str_index++;
		}
		while (s[index] != '\0' && s[index] != c)
			index++;
	}
	str[str_index] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	word_count;
	char	**str;

	index = 0;
	word_count = 0;
	if (s == 0)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] != '\0' && s[index] == c)
			index++;
		if (s[index] != '\0')
			word_count++;
		while (s[index] != '\0' && s[index] != c)
			index++;
	}
	str = malloc((word_count + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	str = fill_str(s, c, str, word_count);
	return (str);
}
