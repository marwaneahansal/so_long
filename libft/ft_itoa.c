/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:01:48 by mahansal          #+#    #+#             */
/*   Updated: 2022/10/27 02:53:54 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int number)
{
	int	digits_count;

	digits_count = 1;
	while (number > 9)
	{
		number /= 10;
		digits_count++;
	}
	return (digits_count);
}

static char	*set_number(char *str, int sign, int digits_count, int number)
{
	int	index;

	index = digits_count;
	if (sign == 1)
	{
		while (index > 0)
		{
			str[index] = number % 10 + '0';
			number = number / 10;
			index--;
		}
		str[0] = '-';
	}
	else
	{
		index -= 1;
		while (index >= 0)
		{
			str[index] = number % 10 + '0';
			number = number / 10;
			index--;
		}
	}
	str[digits_count + sign] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		digits_count;
	int		sign;
	int		number;
	char	*str;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	number = n;
	digits_count = count_digits(number);
	str = malloc((digits_count + sign + 1) * sizeof(char));
	if (!str)
		return (0);
	return (set_number(str, sign, digits_count, number));
}
