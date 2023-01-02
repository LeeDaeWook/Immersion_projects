/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:38:05 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/02 22:45:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_len(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_str_is_numeric(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_len(str);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}