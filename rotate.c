#include "push_swap.h"

/*
 * Top node to bottom position
*/
void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int				len;

	len = ft_lstsize(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

void	ra(t_stack **a, int print_check)
{
	rotate(a);
	if (print_check == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print_check)
{
	rotate(b);
	if (print_check == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print_check)
{
	rotate(a);
	rotate(b);
	if (print_check == 1)
		write(1, "rr\n", 3);
}
