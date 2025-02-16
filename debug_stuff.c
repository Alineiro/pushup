#include "push_swap.h"

void	ft_print_lst(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
	{
		printf("Empty List.\n\n");
		return;
	}
	while (lst->next != NULL)
	{
		printf("Val of '%d' node is: '%d'\n", i, (int)lst->val);
		i++;
		lst = lst->next;
	}
	printf("Val of '%d' node is: '%d'\n\n", i, (int)lst->val);
}

void	print_array(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("number: '%d' is: '%d'\n",i,nums[i]);
		i++;
	}
}

void	exit_cleanup(int *nums, t_stack *stack_a, t_stack *stack_b)
{
	if (nums)
		free(nums);
	if (stack_a)
		ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
