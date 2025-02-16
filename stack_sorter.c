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
		//WHY ++I INSTEAD OF I++, HAVE TO TEST-
		++i;
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
	//printf("val of node passed to prep: '%d'\n",cheapest->val);
	while (*stack != cheapest)
	{
		if (stack_id == 'a')
		{
			if (cheapest->median == true)
			{
				//printf("stack_id = 'a' && above_median true\n");
				ra(stack, true);
			}
			else
			{
				//printf("stack_id = 'a' && above_median false\n");
				rra(stack, true);
			}
		}
		else if (stack_id == 'b')
		{
			if (cheapest->median == true)
			{
				//printf("stack_id = 'b' && above_median true\n");
				rb(stack, true);
			}
			else
			{
				//printf("stack_id = 'b' && above_median false\n");
				rrb(stack, true);
			}
		}
	}
}

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
	{
		//printf("first condition stack_sorter condition is triggered\n");
		pb(stack_b, stack_a, true);
	}
	if (len_a-- > 3 && check_sort(*stack_a) == 1)
	{
		//printf("second condition stack_sorter condition is triggered\n");
		pb(stack_b, stack_a, true);
	}
	while (len_a-- > 3 && check_sort(*stack_a) == 1)
	{
		//printf("loop condition stack_sorter condition is triggered\n");
		init_nodes_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	/*printf("len condtions end and threesort is called, both lists are printed before\n");
	ft_print_lst(*stack_a);
	printf("\n\n");
	ft_print_lst(*stack_b);*/
	three_sort(stack_a);
	//printf("\nprinting stack_a after sorting\n");
	//ft_print_lst(*stack_a);
	while (*stack_b)
	{
		//printf("loop condition of b condition stack_sorter condition is triggered\n");
		init_nodes_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	/*printf("printing both lists before finishing\n");
	ft_print_lst(*stack_a);
	printf("\n\n");
	ft_print_lst(*stack_b);*/
	get_idx_median(*stack_a);
	put_min_on_top(stack_a);
}
