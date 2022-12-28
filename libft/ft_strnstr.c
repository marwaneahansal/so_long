/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:00:32 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:26:53 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_needle(
	const char *hystack,
	const char *needle,
	size_t n,
	size_t hystack_index)
{
	size_t	needle_len;
	size_t	index;

	needle_len = ft_strlen(needle);
	index = 0;
	while (
		needle[index] == hystack[index]
		&& index < needle_len
		&& hystack_index < n)
	{
		index++;
		hystack_index++;
	}
	if (index == needle_len)
		return (1);
	return (-1);
}

char	*ft_strnstr(const char *hystack, const char *needle, size_t n)
{
	size_t	hystack_index;

	hystack_index = 0;
	if (needle[0] == '\0')
		return ((char *) hystack);
	if (n != 0)
	{
		while (hystack[hystack_index] != '\0' && hystack_index < n)
		{
			if (hystack[hystack_index] == needle[0])
			{
				if (check_needle(
						hystack + hystack_index,
						needle, n, hystack_index) == 1)
					return ((char *) &hystack[hystack_index]);
			}
			hystack_index++;
		}
	}
	return (0);
}
