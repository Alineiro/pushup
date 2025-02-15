#include "push_swap.h"

void	swap(t_stack **head)
{
	int	len;

	len = ft_lstsize(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool print_check)
{
	swap(a);
	if (print_check == true)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool print_check)
{
	swap(b);
	if (print_check == true)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print_check)
{
	swap(a);
	swap(b);
	if (print_check == true)
		write(1, "ss\n", 3);
}
