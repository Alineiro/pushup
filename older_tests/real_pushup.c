#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//MINUTE 21, HOW TO CHECK THERE ARE AT LEAST TWO NON-EMPTY ARGUMENTS?
//VALUES THAT ARE EMPTY ARE DETECTED AS 0, IF THERE ARE MORE THAN 2 EMPTY
//VALUES, BOTH COUNT AS 0 AND BREAK THE PROGRAM BECAUSE THE REPEAT FUNCTION
//GETS TRIGGERED. HOWEVER THEY DONT COUNT TO TOTAL_NUMS.
//TO STOP THIS, MUST MAKE THE PROGRAM COMPLETELY IGNORE EMPTY VALUES, THEY
//SHOULDNT BE STORED IN NUMS.

//CHECK CHATGPT FOR SOLUTION.

//CHECK OTHER IMPLEMENTATIONS OF PUSH SWAP TO SEE IF PEOPLE USE THE LST LIBFT
//FUNCTIONS OR IF THEY CREATE NEW ONES, THIS IS TO SEE IF THEY CAN BE REUSED SOMEHOW.

//DO I NEED TO SKIP ALL TRAILING SPACES OR NOT? IF SO, ADD A WHILE (I == ' ') I++;
//INSIDE THE SUPER ATOI

//SHOULD I ALLOCATE + 1 IN THE NUMS CALLOC, OR NOT? SEEMS NOT, IT WORKS ANYWAY,
//IN FACT +1 STORES AND EXTRA 4 BYTES THAT ARENT USED, HOWEVER I DONT GET LEAKS
//BUT WILL LEAVE IT FOR NOW.

typedef struct	s_stack
{
	int	val;
	struct s_stack	*next;
}		t_stack;

void	print_array(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("number: '%d' is: '%d'\n",i,nums[i]);
		i++;
	}
}

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

void	ft_print_lst(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
	{
		printf("Empty List.\n");
		return;
	}
	while (lst->next != NULL)
	{
		printf("Val of '%d' node is: '%d'\n", i, (int)lst->val);
		i++;
		lst = lst->next;
	}
	printf("Val of '%d' node is: '%d'\n", i, (int)lst->val);
}

t_stack  *ft_lstlast(t_stack *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next != NULL)
                lst = lst->next;
        return (lst);
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

int	get_total_nums(char **av)
{
	int	i;
	int	j;
	int	bol;
	int	total;

	i = 1;
	total = 0;
	while (av[i])
	{
		j = 0;
		bol = 0;
		if (!av[i][0])
		{
			i++;
			continue ;
		}
		while (av[i][j])
		{
			if (av[i][j] != ' ')
			{
				if (bol == 0)
				{
					bol = 1;
					total++;
				}
			}
			else
				bol = 0;
			j++;
		}
		i++;
	}
	return (total);
}

int	check_repeat(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
			{
				printf("num[%d]: '%d', detected to be = num[%d]: '%d'\n",i,nums[i],j,nums[j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	super_atoi(char *str, int *nums)
{
	long	n;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + (str[i++] - '0');
		if (((n * sign) > INT_MAX) || ((n * sign) < INT_MIN))
			return (-1);
	}
	if (str[i] == '\0')
	{
		*nums = n * sign;
		return (1);
	}
	return (-1);
}

int	*copy_args(char **av, int *nums)
{
	int	i;
	int	total_nums;

	i = 1;
	total_nums = get_total_nums(av);
	printf("val of total_nums: '%d'\n",total_nums);
	nums = (int *)calloc((total_nums + 1), sizeof(int));
	if (!nums)
		exit(EXIT_FAILURE);
	while (av[i])
	{
		if (av[i] && av[i][0])
		{
			if (super_atoi(av[i], &nums[i - 1]) == -1)
			{
				printf("atoi returned -1, num: '%s' not valid\n",av[i]);
				free(nums);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return (nums);
}

void	struct_init(t_stack **stack_a, int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("allocates list, nums[i] == '%d'\n",nums[i]);
		ft_lstadd_back(stack_a, ft_lstnew(nums[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	*nums;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 2 || (get_total_nums(av) < 2))
	{
		printf("input more valid arguments\n");
		exit(EXIT_FAILURE);
	}
	nums = copy_args(av, nums);
	if (!nums)
	{
		printf("failure in copying\n");
		exit(EXIT_FAILURE);
	}
	if (check_repeat(nums, get_total_nums(av)) == -1)
	{
		printf("numbers are repeated\n");
		free(nums);
		exit(EXIT_FAILURE);
	}
	printf("input is valid and its value is:\n\n");
	print_array(nums, get_total_nums(av));
	struct_init(&stack_a, nums, get_total_nums(av));
	ft_print_lst(stack_a);
	ft_lstclear(&stack_a);
	return (free(nums), 0);
}
