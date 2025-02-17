#include "push_swap.h"

int	initial_checks(int ac, char **av, int **nums)
{
	int	total_nums;

	total_nums = get_total_nums(av);
	if (ac <= 2 || (total_nums < 2))
		exit(EXIT_FAILURE);
	if (copy_args(av, nums) == -1)
		return (-1);
	if (check_repeat(*nums, total_nums) == -1)
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*nums;

	stack_a = NULL;
	stack_b = NULL;
	nums = NULL;
	if (initial_checks(ac, av, &nums) == -1)
		exit_cleanup(nums, stack_a, stack_b);
	struct_init(&stack_a, nums, get_total_nums(av));
	if (check_sort(stack_a) == -1)
		exit_cleanup(nums, stack_a, stack_b);
	start_sorting(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	return (free(nums), 0);
}
