#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print_check)
{
	push(a, b);
	if (print_check == true)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print_check)
{
	push(b, a);
	if (print_check == true)
		write(1, "pb\n", 3);
}
