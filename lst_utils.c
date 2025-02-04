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

t_stack  *ft_lstnew(int content)
{
        t_stack  *newn;

        newn = (t_stack *)malloc(sizeof(t_stack));
        if (!newn)
                return (newn = NULL, NULL);
        newn->val = content;
        newn->next = NULL;
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
                return ;
        }
        else
        {
		printf("val assigned to last node\n");
                last = ft_lstlast(*lst);
                last->next = new;
        }
}
