/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:39:02 by daewoole          #+#    #+#             */
/*   Updated: 2022/09/29 16:44:47 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	n[3];

	n[0] = '0';
	while (n[0] <= '7')
	{
		n[1] = n[0] + 1;
		while (n[1] <= '8')
		{
			n[2] = n[1] + 1;
			while (n[2] <= '9')
			{
				write(1, &n[0], 1);
				write(1, &n[1], 1);
				write(1, &n[2], 1);
				if (n[0] == '7' && n[1] == '8' && n[2] == '9')
					return ;
				write(1, ", ", 2);
				n[2]++;
			}
			n[1]++;
		}
		n[0]++;
	}
}
