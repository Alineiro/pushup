#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

//SHOULD BE FINISHED, HAVE TO ADD REMAINING FUNCTIONS TO .H, AND AFTER THAT
//IT SHOULD BE READY. THERE MIGHT BE MANY ISSUES BECAUSE I CHANGE THE WAY I 
//MANAGE A FEW THINGS, MAINLY BECAUSE OF MY USAGE OF INTS INSTEAD OF BOOLEANS.

//MISSING ADDING EASY ERROR HANDLING FUNCTIONS (PRINT "error" AND EXIT)

//HOW TO CHECK THERE ARE AT LEAST TWO NON-EMPTY ARGUMENTS?
//VALUES THAT ARE EMPTY ARE DETECTED AS 0, IF THERE ARE MORE THAN 2 EMPTY
//VALUES, BOTH COUNT AS 0 AND BREAK THE PROGRAM BECAUSE THE REPEAT FUNCTION
//GETS TRIGGERED. HOWEVER THEY DONT COUNT TO TOTAL_NUMS.
//TO STOP THIS, MUST MAKE THE PROGRAM COMPLETELY IGNORE EMPTY VALUES, THEY
//SHOULDNT BE STORED IN NUMS.

//CHECK CHATGPT FOR SOLUTION, CONVO PUSHUP.


//ID LIKE TO UNDERSTAND BETTER WHY ARE THE STACKS PASSED WITH A *, WITHOUT IT,
//LIKE (*STACK), ETC. MY ISSUE WITH UNDERSTANDING HAPPENS MAINLY IN THE 
//SORTING AND MOVEMENT FUNCTIONS, ASK CHATGPT I GUESS.

//SHOULD I DIRECTLY CALL EXIT EVERY TIME I GET AN ERROR THAT SHOULD CLOSE THE
//PROGRAM WITHOUT FREEING EVERYTHING (NUMS ARRAY, STACKS, ETC)? OR SHOULD I FREE
//ANYWAY? IS IT BAD PRACTICE, DOES IT MATTER?

//DO I NEED TO SKIP ALL TRAILING SPACES OR NOT? IF SO, ADD A WHILE (I == ' ') I++;
//INSIDE THE SUPER ATOL

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
//

//LST_UTILS FUNCTIONS
//
void	ft_lstdelone(t_stack *lst);
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
int	*copy_args(char **av, int *nums);
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
