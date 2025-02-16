#include "push_swap.h"

void	set_target_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_idx;

	while (stack_b)
	{
		best_idx = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->val > stack_b->val
				&& current_a->val < best_idx)
			{
				best_idx = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_idx == LONG_MAX)
		{
			stack_b->target = find_lstmin(stack_a);
		//	printf("best idx == long_max target of stack_b is: %d\n",stack_b->target->val);
		}
		else
		{
			stack_b->target = target_node;
		//	printf("else target of stack_b is: %d\n",stack_b->target->val);
		}
		stack_b = stack_b->next;
	}
}

void	init_nodes_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	get_idx_median(stack_a);
	get_idx_median(stack_b);
	set_target_stack_b(stack_a, stack_b);
}
