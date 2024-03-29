/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:11:26 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/04 14:18:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	*ft_check(unsigned char *s1, unsigned char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i > j)
		return (s1);
	return (s2);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	i = 0;
	un_s1 = (unsigned char *) s1;
	un_s2 = (unsigned char *) s2;
	while (*(ft_check(un_s1, un_s2) + i) != '\0')
	{
		if (un_s1[i] > un_s2[i])
			return (un_s1[i] - un_s2[i]);
		else if (un_s1[i] < un_s2[i])
			return (un_s1[i] - un_s2[i]);
		i++;
	}
	return (0);
}
