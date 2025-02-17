#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int		len;

	len = ft_lstsize(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool print_check)
{
	rotate(a);
	if (print_check == true)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print_check)
{
	rotate(b);
	if (print_check == true)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print_check)
{
	rotate(a);
	rotate(b);
	if (print_check == true)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target && *stack_a != cheapest)
		rr(stack_a, stack_b, true);
	get_idx_median(*stack_a);
	get_idx_median(*stack_b);
}
