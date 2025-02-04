#include "push_swap.h"

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

int	super_atol(char *str, int *nums)
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
			if (super_atol(av[i], &nums[i - 1]) == -1)
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
