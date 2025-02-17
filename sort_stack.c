#include "push_swap.h"

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest_node(*stack_a);
	if (cheapest->median == true && cheapest->target->median == true)
		rotate_both(stack_a, stack_b, cheapest);
	else if (cheapest->median == false && cheapest->target->median == false)
		r_rotate_both(stack_a, stack_b, cheapest);
	push_prep(stack_a, cheapest, 'a');
	push_prep(stack_b, cheapest->target, 'b');
	pb(stack_b, stack_a, true);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	push_prep(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, true);
}

void	three_sort(t_stack **stack_a)
{
	t_stack	*max_node;

	max_node = find_lstmax(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a, true);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, true);
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a, true);
}

void	stack_sorter(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3 && check_sort(*stack_a) == 1)
		pb(stack_b, stack_a, true);
	if (len_a-- > 3 && check_sort(*stack_a) == 1)
		pb(stack_b, stack_a, true);
	while (len_a-- > 3 && check_sort(*stack_a) == 1)
	{
		init_nodes_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		init_nodes_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	get_idx_median(*stack_a);
	put_min_on_top(stack_a);
}

void	start_sorting(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, true);
	else if (ft_lstsize(*stack_a) == 3)
		three_sort(stack_a);
	else
		stack_sorter(stack_a, stack_b);
}
