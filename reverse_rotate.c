#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = ft_lstsize(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool print_check)
{
	reverse_rotate(a);
	if (print_check == true)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print_check)
{
	reverse_rotate(b);
	if (print_check == true)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print_check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_check == true)
		write(1, "rrr\n", 4);
}

void	r_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rrr(stack_a, stack_b, true);
	get_idx_median(*stack_a);
	get_idx_median(*stack_b);
}
