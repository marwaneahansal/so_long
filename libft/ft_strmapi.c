/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:27:30 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:56:13 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	index;
	char	*str;

	if (s == 0 || f == 0)
		return (0);
	s_len = ft_strlen(s);
	index = 0;
	str = malloc((s_len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (index < s_len)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
