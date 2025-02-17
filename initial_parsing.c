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
		while (av[i][j])
		{
			if (av[i][j] != ' ' && bol == 0)
			{
				bol = 1;
				total++;
			}
			else if (av[i][j] == ' ')
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
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sort(t_stack *lst)
{
	if (!lst)
		return (-1);
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (1);
		lst = lst->next;
	}
	return (-1);
}

int	super_atol(char *str, int *nums)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + (str[i++] - '0');
		if (((n * sign) > INT_MAX) || ((n * sign) < INT_MIN))
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	*nums = n * sign;
	return (1);
}

int	copy_args(char **av, int **nums)
{
	int	i;
	int	total_nums;

	i = 1;
	total_nums = get_total_nums(av);
	*nums = (int *)calloc((total_nums), sizeof(int));
	if (!*nums)
		return (-1);
	while (av[i])
	{
		if (av[i] && av[i][0])
		{
			if (super_atol(av[i], &((*nums)[i - 1])) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
