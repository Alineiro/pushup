#include "push_swap.h"

void	get_idx_median(t_stack *stack)
{
	int	i;
	int	med;

	i = 0;
	if (!stack)
		return ;
	med = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->idx = i;
		if (i <= med)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	put_min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->val != find_lstmin(*stack_a)->val)
	{
		if (find_lstmin(*stack_a)->median == true)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	push_prep(t_stack **stack, t_stack *cheapest, char stack_id)
{
	while (*stack != cheapest)
	{
		if (stack_id == 'a')
		{
			if (cheapest->median == true)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_id == 'b')
		{
			if (cheapest->median == true)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
