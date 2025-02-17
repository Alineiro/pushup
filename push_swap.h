#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				idx;
	int				cost;
	bool			median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

//ERROR && CLEANUP FUNCTIONS
//
void	ft_lstclear(t_stack **lst);
void	exit_cleanup(int *nums, t_stack *stack_a, t_stack *stack_b);
//

//INIT NODES STACK A FUNCTIONS
//
void	set_target_stack_a(t_stack *stack_a, t_stack *stack_b);
void	analyse_cost_stack_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_stack_a(t_stack *stack_a, t_stack *stack_b);
//

//INIT NODES STACK B FUNCTIONS
//
void	set_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_stack_b(t_stack *stack_a, t_stack *stack_b);
//

//LST UTILS FUNCTIONS
//
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*find_lstmin(t_stack *stack);
t_stack	*find_lstmax(t_stack *stack);
int		ft_lstsize(t_stack *lst);
//

//INITIAL PARSING FUNCTIONS
//
int		get_total_nums(char **av);
int		check_repeat(int *nums, int size);
int		check_sort(t_stack *lst);
int		super_atol(char *str, int *nums);
int		copy_args(char **av, int **nums);
int		initial_checks(int ac, char **av, int **nums);
//

//MOVEMENT FUNCTIONS
//
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool print_check);
void	pb(t_stack **b, t_stack **a, bool print_check);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool print_check);
void	rrb(t_stack **b, bool print_check);
void	rrr(t_stack **a, t_stack **b, bool print_check);
void	r_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print_check);
void	rb(t_stack **b, bool print_check);
void	rr(t_stack **a, t_stack **b, bool print_check);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	swap(t_stack **head);
void	sa(t_stack **a, bool print_check);
void	sb(t_stack **b, bool print_check);
void	ss(t_stack **a, t_stack **b, bool print_check);
//

//SORT UTILS FUNCTIONS
//
void	get_idx_median(t_stack *stack);
void	set_cheapest_node(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);
void	put_min_on_top(t_stack **stack_a);
void	push_prep(t_stack **stack, t_stack *cheapest, char stack_id);
//

//SORT STACK FUNCTIONS
//
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	three_sort(t_stack **stack_a);
void	stack_sorter(t_stack **stack_a, t_stack **stack_b);
void	start_sorting(t_stack **stack_a, t_stack **stack_b);
//

//STRUCT INIT FUNCTIONS
//
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	struct_init(t_stack **stack_a, int *nums, int size);
//

#endif
