#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*min_node;
	t_stack	*max_node;
	int	*nums;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 2 || (get_total_nums(av) < 2))
	{
		printf("input more valid arguments\n");
		exit(EXIT_FAILURE);
	}
	nums = copy_args(av, nums);
	if (!nums)
	{
		printf("failure in copying\n");
		exit(EXIT_FAILURE);
	}
	if (check_repeat(nums, get_total_nums(av)) == -1)
	{
		printf("numbers are repeated\n");
		free(nums);
		exit(EXIT_FAILURE);
	}
	printf("input is valid and its value is:\n\n");
	print_array(nums, get_total_nums(av));
	struct_init(&stack_a, nums, get_total_nums(av));
	ft_print_lst(stack_a);
	if (check_sort(stack_a) == -1)
	{
		printf("stack already sorted, program exits\n");
		free(nums);
		ft_lstclear(&stack_a);
		exit(EXIT_FAILURE);
	}
	min_node = find_lstmin(stack_a);
	printf("val of min_node is: '%d'\n",min_node->val);
	max_node = find_lstmax(stack_a);
	printf("val of max_node is: '%d'\n",max_node->val);
	if (ft_lstsize(stack_a) == 2)
		sa(&stack_a, true);
	else if (ft_lstsize(stack_a) == 3)
		three_sort(&stack_a);
	else
	{
		printf("enters stack_sorting function\n");
		stack_sorter(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	return (free(nums), 0);
}
