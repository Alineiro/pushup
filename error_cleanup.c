#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	temp = NULL;
	if (!lst || !lst[0])
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	exit_cleanup(int *nums, t_stack *stack_a, t_stack *stack_b)
{
	if (nums)
		free(nums);
	if (stack_a)
		ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
