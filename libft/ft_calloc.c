/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:52:35 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:31:50 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*char_ptr;
	size_t	index;

	index = 0;
	if (size > 0 && count > SIZE_MAX / size)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	char_ptr = (char *) ptr;
	while (index < (size * count))
	{
		char_ptr[index] = '\0';
		index++;
	}
	return (char_ptr);
}
