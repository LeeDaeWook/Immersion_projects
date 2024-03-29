/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:00:17 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:31:24 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_first(t_deque *from, t_deque *to)
{
	int	**count;
	int	min_idx;

	while (from->size > 0)
	{
		if (to->size < 2)
			push(to, from);
		else if (to->stack == STACK_B)
		{
			count = greedy(from, to);
			min_idx = find_min_instructions(count, from->size);
			execute_instructions(count[min_idx], from, to);
			free_count(count, (from->size + 1));
		}
		if (from->stack == STACK_A && from->size == 3)
		{
			last_three(from);
			from->max = from->bottom;
			return ;
		}
	}
}

void	last_three(t_deque *stack)
{
	t_node	*temp;

	temp = find_min_node(stack);
	stack->min = temp;
	final_sort(stack, temp);
	temp = stack->top;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
		{
			swap(stack);
			last_three(stack);
			return ;
		}
		temp = temp->next;
	}
}

void	final_sort(t_deque *stack, t_node *node)
{
	int	idx;

	idx = find_idx(node, stack);
	while (node->num != stack->top->num)
	{
		if (idx <= (stack->size / 2))
			rotate(stack, RA);
		else if (idx > (stack->size / 2))
			reverse_rotate(stack, RRA);
	}
}

void	under_three(t_deque *stack)
{
	last_three(stack);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_deque	deque_a;
	t_deque	deque_b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_bzero((void *)&deque_a, sizeof(t_deque));
	deque_a.top = add_node();
	make_list(++argv, &deque_a, 0, deque_a.top);
	if (deque_a.size <= 3)
		under_three(&deque_a);
	deque_a.stack = STACK_A;
	if (!deque_a.size)
		print_error();
	ft_bzero((void *)&deque_b, sizeof(t_deque));
	deque_b.stack = STACK_B;
	push_swap_first(&deque_a, &deque_b);
	push_swap_second(&deque_b, &deque_a);
	final_sort(&deque_a, deque_a.min);
	free_linked_list(&deque_a);
	return (EXIT_SUCCESS);
}
