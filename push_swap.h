#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

//MINUTE 27, BEFORE CONTINUING, I HAVE TO MAKE SOME UTILS FUNCTIONS THAT ARE NOT
//RELATED TO THE ALGORITHM ITSELF, THESE FUNCTIONS CAN BE FOUND IN GITHUB TUTORIAL
//EASY ERROR HANDLING (PRINT "error" AND EXIT)
//SHOULD BE DONE MOVEMENTS (WILL WAIT TO MAKE THEM UNTIL I CONFIRM SHE DOESNT COVER THEM)
//??? OBTAIN MIN AND MAX NODES (SHOULD BE EASY, LST[0] AND LST[LST_LAST], MUST TEST)

//PROBLEM WITH MOVEMENTS EXECUTING WHEN LISTS DO NOT HAVE MORE THAN ONE NODE,
//CAUSING AN ERROR OF INVALID USAGE OF UNALLOCATED VALUE, (VALGRIND), NEEDS MORE
//TESTING, SO FAR I ONLY SEE IT WHEN EXECUTING RRR WHEN STACK_B HAS ONLY ONE VALUE,
//NEED TO UNDERSTAND WHY (LIKELY ADD A CHECK IF (STACK_X || LSTSIZE(STACK_X > 1), ETC).
//HOWEVER, I DONT KNOW IF THIS IS MANAGED BY THE ALGORITHM ITSELF, AND THATS WHY
//THE GITHUBS DONT MANAGE THE CASE.

//HOW TO CHECK THERE ARE AT LEAST TWO NON-EMPTY ARGUMENTS?
//VALUES THAT ARE EMPTY ARE DETECTED AS 0, IF THERE ARE MORE THAN 2 EMPTY
//VALUES, BOTH COUNT AS 0 AND BREAK THE PROGRAM BECAUSE THE REPEAT FUNCTION
//GETS TRIGGERED. HOWEVER THEY DONT COUNT TO TOTAL_NUMS.
//TO STOP THIS, MUST MAKE THE PROGRAM COMPLETELY IGNORE EMPTY VALUES, THEY
//SHOULDNT BE STORED IN NUMS.

//CHECK CHATGPT FOR SOLUTION, CONVO PUSHUP.


//SHOULD I DIRECTLY CALL EXIT EVERY TIME I GET AN ERROR THAT SHOULD CLOSE THE
//PROGRAM WITHOUT FREEING EVERYTHING (NUMS ARRAY, STACKS, ETC)? OR SHOULD I FREE
//ANYWAY? IS IT BAD PRACTICE, DOES IT MATTER?

//DO I NEED TO SKIP ALL TRAILING SPACES OR NOT? IF SO, ADD A WHILE (I == ' ') I++;
//INSIDE THE SUPER ATOL

//SHOULD I ALLOCATE + 1 IN THE NUMS CALLOC, OR NOT? SEEMS NOT, IT WORKS ANYWAY,
//IN FACT +1 STORES AND EXTRA 4 BYTES THAT ARENT USED, HOWEVER I DONT GET LEAKS
//SO I WILL LEAVE IT FOR NOW.

typedef struct	s_stack
{
	int	val;
	int	idx;
	int	cost;
	int	median;
	int	cheap;
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
void	pa(t_stack **a, t_stack **b, int print_check);
void	pb(t_stack **b, t_stack **a, int print_check);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, int print_check);
void	rrb(t_stack **b, int print_check);
void	rrr(t_stack **a, t_stack **b, int print_check);
void	rotate(t_stack **stack);
void	ra(t_stack **a, int print_check);
void	rb(t_stack **b, int print_check);
void	rr(t_stack **a, t_stack **b, int print_check);
void	swap(t_stack **head);
void	sa(t_stack **a, int print_check);
void	sb(t_stack **b, int print_check);
void	ss(t_stack **a, t_stack **b, int print_check);
//

#endif
