/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:27:31 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/03 18:36:19 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_copy(char *dest, char *src, unsigned int size,
		unsigned int dest_len)
{
	unsigned int	src_len;

	src_len = 0;
	if (size > dest_len)
	{
		while (*src != '\0' && (src_len + 1) < (size - dest_len))
		{
			*dest++ = *src++;
			src_len++;
		}
		*dest = '\0';
	}
	while (*src != '\0')
	{
		src_len++;
		src++;
	}
	return (src_len);
}

unsigned int	ft_strlcat(char*dest, char*src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = 0;
	dest_len = 0;
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	src_len = ft_copy(dest, src, size, dest_len);
	if (size <= dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}