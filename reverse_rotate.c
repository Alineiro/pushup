#include "push_swap.h"

/*
 * Bottom to top
*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = ft_lstsize(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int print_check)
{
	reverse_rotate(a);
	if (print_check == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print_check)
{
	reverse_rotate(b);
	if (print_check == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print_check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_check == 1)
		write(1, "rrr\n", 4);
}
