/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:47:25 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/17 16:49:01 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*cp_src;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	cp_src = malloc(sizeof(char) * (src_len + 1));
	if (!cp_src)
		return (NULL);
	while (*src)
		*cp_src++ = *src++;
	*cp_src = '\0';
	cp_src = cp_src - src_len;
	return (cp_src);
}
