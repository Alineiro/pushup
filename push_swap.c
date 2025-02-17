#include "push_swap.h"

int	initial_checks(int ac, char **av, int **nums)
{
	int	total_nums;

	total_nums = get_total_nums(av);
	//printf("val of total_nums: '%d'\n",total_nums);
	if (ac <= 2 || (total_nums < 2))
		return (-1);	
	if (copy_args(av, nums) == -1)
		return (-1);
	if (check_repeat(*nums, total_nums) == -1)
		return (-1);
	return (1);
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
/*
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
	three_sort(stack_a);
	while (*stack_b)
	{
		//printf("loop condition of b condition stack_sorter condition is triggered\n");
		init_nodes_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	get_idx_median(*stack_a);
	put_min_on_top(stack_a);
}*/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*min_node;
	t_stack	*max_node;
	int	*nums;

	stack_a = NULL;
	stack_b = NULL;
	nums = NULL;
	if (initial_checks(ac, av, &nums) == -1)
		exit_cleanup(nums, stack_a, stack_b);
	/*if (ac <= 2 || (get_total_nums(av) < 2))
		exit_cleanup(nums, stack_a, stack_b);
	if (copy_args(av, &nums) == -1)
		exit_cleanup(nums, stack_a, stack_b);
	if (check_repeat(nums, get_total_nums(av)) == -1)
		exit_cleanup(nums, stack_a, stack_b);*/
	//print_array(nums, get_total_nums(av));
	struct_init(&stack_a, nums, get_total_nums(av));
	if (check_sort(stack_a) == -1)
		exit_cleanup(nums, stack_a, stack_b);
	min_node = find_lstmin(stack_a);
	max_node = find_lstmax(stack_a);
	start_sorting(&stack_a, &stack_b);
	/*if (ft_lstsize(stack_a) == 2)
		sa(&stack_a, true);
	else if (ft_lstsize(stack_a) == 3)
		three_sort(&stack_a);
	else
		stack_sorter(&stack_a, &stack_b);*/
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	return (free(nums), 0);
}
