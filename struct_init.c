#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*newn;

	newn = (t_stack *)malloc(sizeof(t_stack));
	if (!newn)
		return (newn = NULL, NULL);
	newn->val = content;
	newn->next = NULL;
	newn->cheapest = 0;
	return (newn);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	struct_init(t_stack **stack_a, int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack_a, ft_lstnew(nums[i]));
		i++;
	}
}
