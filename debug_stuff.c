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
