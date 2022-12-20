/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:31:23 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:32:28 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*present_node;

	while (lst)
	{
		present_node = lst;
		lst = lst->next;
	}
	return (present_node);
}
/*
#include <stdio.h>

int main(void)
{
	t_list	*head;
	t_list	first;
	t_list	second;
	int	content;

	head = &first;
	first.next = &second;
	second.next = 0;
	
	content = 12345;
	second.content = &content; 
	
	printf("%d\n", *(int*)ft_lstlast(head)->content);

	return (0);
}
*/