/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:28:33 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:25:33 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	else
		i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}	
	return (i);
}

void	ft_excute(int n, char *result, int i)
{
	int	sign;

	sign = 1;
	if (n == -2147483648)
	{
		result[i--] = n % 10 * -1 + '0';
		n /= 10;
	}
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	if (i == 0)
		result[i] = n + '0';
	while (i > 0)
	{
		result[i--] = n % 10 + '0';
		n /= 10;
		if (i == 0 && sign < 0)
			result[i] = '-';
		else if (i == 0 && sign > 0)
			result[i] = n % 10 + '0';
	}	
}

char	*ft_itoa(int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_len(n) + 1));
	if (!result)
		return (0);
	ft_excute(n, result, ft_len(n) - 1);
	result[ft_len(n)] = '\0';
	return (result);
}
