#include "push_swap.h"

void	set_target_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_idx;

	while (stack_a)
	{
		best_idx = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->val < stack_a->val
				&& current_b->val > best_idx)
			{
				best_idx = current_b->val;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_idx == LONG_MIN)
			stack_a->target = find_lstmax(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	analyse_cost_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->idx;
		printf("val of a above_median bool: '%d'\n",stack_a->median);
		printf("val of a target above_median bool: '%d'\n",stack_a->target->median);
		if (stack_a->median == false)
		{
			printf("stack_a above median found false\n");
			stack_a->cost = len_a - (stack_a->idx);
		}
		if (stack_a->target->median == true)
		{
			printf("stack_a target median is found to be true\n");
			stack_a->cost += stack_a->target->idx;
		}
		else
		{
			printf("stack_a aboe median true and target b above_median is false\n");
			stack_a->cost += len_b - (stack_a->target->idx);
		}
		stack_a = stack_a->next;
	}
}

void	init_nodes_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	get_idx_median(stack_a);
	get_idx_median(stack_b);
	set_target_stack_a(stack_a, stack_b);
	analyse_cost_stack_a(stack_a, stack_b);
	set_cheapest_node(stack_a);
}
