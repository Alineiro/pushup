#include "push_swap.h"

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		printf("Val of deleted node is: '%d'\n",(int)lst->val);
		free(lst);
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	
	temp = NULL;
	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_stack  *ft_lstlast(t_stack *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next != NULL)
                lst = lst->next;
        return (lst);
}

t_stack	*find_lstmin(t_stack *stack)
{
	long			min; 
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*find_lstmax(t_stack *stack)
{
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	ft_lstsize(t_stack *lst)
{
	int	lcount;

	lcount = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		lcount++;
	}
	return (lcount);
}

int	check_sort(t_stack *lst)
{
	if (!lst)
		return (-1);
	while (lst->next)
	{
		//printf("testing value lst->val: '%d' and lst->next->val: '%d'\n",lst->val,lst->next->val);
		if (lst->val > lst->next->val)
		{
			//printf("lst->val: '%d' is < to lst->next->val: '%d', so lst is not sorted\n",lst->val,lst->next->val);
			return (1);
		}
		lst = lst->next;
	}
	//printf("lst is sorted\n");
	return (-1);
}

t_stack  *ft_lstnew(int content)
{
        t_stack  *newn;

        newn = (t_stack *)malloc(sizeof(t_stack));
        if (!newn)
                return (newn = NULL, NULL);
        newn->val = content;
        newn->next = NULL;
	newn->cheapest = 0;
	//newn->prev = NULL;
        return (newn);
}

void    ft_lstadd_back(t_stack **lst, t_stack *new)
{
        t_stack  *last;

        last = NULL;
        if (!new)
                return ;
        if (!lst[0])
        {
		printf("first node doesnt exist, value assigned first val\n");
                lst[0] = new;
		new->prev = NULL;
                return ;
        }
        else
        {
		printf("val assigned to last node\n");
                last = ft_lstlast(*lst);
                last->next = new;
		new->prev = last;
        }
}
