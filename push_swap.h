#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

//LONE SIMBOLS EX (8 - 1 -2) ARE ACCEPTED AND CONVERTED TO A 0 WHEN COPIED TO NUMS,
//THE FUNCTION GET_TOTAL_NUMS COUNTS IT AS A NUMBER.
//ARG="3 767 "23" 1 -1 "-" 9" IN THAT EXAMPLE THE - IS ALSO ACCEPTED.

//THE CHECKER DOESNT CARE ABOUT EMPTY STRINGS """""" OR "6 1 4"""""" 2", ETC.

//IF I PASS SOMETHING LIKE "3 45 -1 0 "4 10 -2" 99" ONLY THE FIRST NUMBER OF
//THE "4 10 -2" STRING IS ACCEPTED, THE REST ARENT TAKEN, AND A MESSAGE 10: COMMAND NOT FOUND
//APPEARS, HOWEVER THE CHECKER ACCEPTS MY OUTPUT AS THE CORRECT ONE.

//ID LIKE TO UNDERSTAND BETTER WHY ARE THE STACKS PASSED WITH A *, WITHOUT IT,
//LIKE (*STACK), ETC. MY ISSUE WITH UNDERSTANDING HAPPENS MAINLY IN THE 
//SORTING AND MOVEMENT FUNCTIONS, ASK CHATGPT I GUESS.


typedef struct	s_stack
{
	int	val;
	int	idx;
	int	cost;
	bool	median;
	bool	cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

//DEBUG FUNCTIONS
//
void	print_array(int *nums, int size);
void	ft_print_lst(t_stack *lst);
void	exit_cleanup(int *nums, t_stack *stack_a, t_stack *stack_b);
//

//LST_UTILS FUNCTIONS
//
void	ft_lstclear(t_stack **lst);
t_stack	*find_lstmin(t_stack *stack);
t_stack	*find_lstmax(t_stack *stack);
t_stack  *ft_lstlast(t_stack *lst);
int	ft_lstsize(t_stack *lst);
t_stack  *ft_lstnew(int content);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
int	check_sort(t_stack *lst);
//

//PARSING FUNCTIONS
//
int	get_total_nums(char **av);
int	check_repeat(int *nums, int size);
int	super_atol(char *str, int *nums);
int	copy_args(char **av, int **nums);
void	struct_init(t_stack **stack_a, int *nums, int size);
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

//SORTING FUNCTIONS
//
void	three_sort(t_stack **stack_a);
void	set_target_stack_a(t_stack *stack_a, t_stack *stack_b);
void	set_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_stack_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_stack_b(t_stack *stack_a, t_stack *stack_b);
void	analyse_cost_stack_a(t_stack *stack_a, t_stack *stack_b);
void	get_idx_median(t_stack *stack);
void	set_cheapest_node(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);
void	put_min_on_top(t_stack **stack_a);
void	push_prep(t_stack **stack, t_stack *cheapest, char stack_id);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	stack_sorter(t_stack **stack_a, t_stack **stack_b);
//

#endif
