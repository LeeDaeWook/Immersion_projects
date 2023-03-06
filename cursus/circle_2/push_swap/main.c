#include "push_swap.h"

t_node *add_node(void)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
    {
        write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
        exit(EXIT_FAILURE);
    }
    new_node->pre = NULL;
    new_node->next = NULL;
    return (new_node);
}

void free_count(int **count, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(count[i]);
        i++;
    }
    free(count);
}

void push_swap1(t_deque *from, t_deque *to)
{
    int **count;
    int min_idx;
    int idx;

    while (from->size > 0)
    {
        if (to->size < 2)
            push(to, from);
        else if (to->stack == STACK_B)
        {
            count = greedy(from, to);
            min_idx = find_min_instructions(count, from->size);
            execute_instructions(count[min_idx], from, to);
            free_count(count, (from->size + 1)); // 이 부분에서 count를 free 해줘야 함
        }
        if (from->stack == STACK_A && from->size == 3)
        {
            last_three(from);
            from->max = from->bottom;
            return;
        }
    }
}

void push_swap2(t_deque *from, t_deque *to)
{
    int *count;
    int idx;

    while (from->size > 0)
    {
        count = (int *)malloc(sizeof(int) * 7);
        ft_bzero((void *)count, sizeof(int) * 7);
        idx = find_location_a(from->top, to);
        if (idx <= (to->size / 2))
        {
            count[RA] = idx;
            recursion_r_rr(count, to, RA);
        }
        else if (idx > (to->size / 2))
        {
            count[RRA] = to->size - idx;
            recursion_r_rr(count, to, RRA);
        }
        push(to, from);
        free(count);
    }
}

void last_three(t_deque *stack)
{
    static int flag;
    t_node *temp;

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
            return;
        }
        temp = temp->next;
    }
}

t_node *find_min_node(t_deque *stack)
{
    t_node *temp;
    t_node *node;
    int min_idx;
    int min_num;

    temp = stack->top;
    min_num = INTEGER_MAX;
    while (temp)
    {
        if (temp->num < min_num)
        {
            min_num = temp->num;
            node = temp;
        }
        temp = temp->next;
    }
    return (node);
}

void final_sort(t_deque *stack, t_node *node)
{
    int idx;

    idx = find_idx(node, stack);
    while (node->num != stack->top->num)
    {
        if (idx <= (stack->size / 2))
            rotate(stack);
        else if (idx > (stack->size / 2))
            reverse_rotate(stack);
    }
}

int main(int argc, char *argv[])
{
    t_deque deque_a;
    t_deque deque_b;

    if (argc < 2)
        exit(EXIT_FAILURE);
    ft_bzero((void*)&deque_a, sizeof(t_deque));
    deque_a.top = add_node();
    make_linkedlist(argv, &deque_a, 0, deque_a.top);
    deque_a.stack = STACK_A;
    if (!deque_a.size)
    {
        write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
        exit(EXIT_FAILURE);
    }
    ft_bzero((void*)&deque_b, sizeof(t_deque));
    deque_b.stack = STACK_B;
    push_swap1(&deque_a, &deque_b);
    push_swap2(&deque_b, &deque_a);
    final_sort(&deque_a, deque_a.min);
    just_print(&deque_a, deque_a.size);
    return (EXIT_SUCCESS);
}