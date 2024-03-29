/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:27:44 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:31:00 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define STANDARD_ERROR 2
# define INTEGER_MAX 2147483647
# define INTEGER_MIN -2147483648
# define RA 0
# define RB 1
# define RR 2
# define RRA 3
# define RRB 4
# define RRR 5
# define TOTAL_IDX 6
# define STACK_A 0
# define STACK_B 1 
# define ROTATE 0
# define REVERSE_ROTATE 1
# define SWAP 2
# define PUSH 3

typedef struct s_node
{
	int				num;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	struct s_node	*top;
	struct s_node	*bottom;
	struct s_node	*max;
	struct s_node	*min;
	int				size;
	int				stack;
}	t_deque;

void		push_swap_first(t_deque *from, t_deque *to);
void		last_three(t_deque *stack);
void		final_sort(t_deque *stack, t_node *node);

void		push_swap_second(t_deque *from, t_deque *to);

void		free_count(int **count, int size);
void		double_free(char **str);
void		free_linked_list(t_deque *stack);

void		is_integer(char *argv);
void		validate_overlap_sorting(t_deque *stack, int num, int *flag);
t_node		*add_node(void);
void		make_list(char *argv[], t_deque *stack, int flag, t_node *temp);

int			find_location_b(t_node *node, t_deque *stack);
int			find_location_a(t_node *node, t_deque *stack);
int			find_idx(t_node *node, t_deque *stack);
int			find_min_instructions(int **count, int size);
t_node		*find_min_node(t_deque *stack);

void		fill_count(t_node *node, t_deque *from, t_deque *to, int *count);
void		r_rr_from(t_node *node, t_deque *stack, int *count, int flag);
void		r_rr_to(int idx, t_deque *stack, int *count, int flag);
void		rr_rrr(int *count);

int			**greedy(t_deque *from, t_deque *to);
void		execute_instructions(int *count, t_deque *from, t_deque *to);
void		recursion_r_rr(int *count, t_deque *stack, int idx);
void		recursion_rr_rrr(int *count, t_deque *from, t_deque *to, int idx);

void		push(t_deque *to, t_deque *from);
void		compare_max_min(t_deque *to);

void		rotate(t_deque *stack, int idx);

void		reverse_rotate(t_deque *stack, int idx);

void		swap(t_deque *stack);

void		print_instructions(int flag, t_deque *stack);

void		under_three(t_deque *stack);
void		print_error(void);

long long	ft_atoi_ll(const char *s);

#endif
