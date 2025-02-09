#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
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
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	return (free(nums), 0);
}
