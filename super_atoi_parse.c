#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//HOW TO CHECK LENGTH OF AN INT ARRAY? ASK CHAT GPT, NECESARY, CHECK WITH PRINT ARRAY FUNC.
//ALSO HAVE TO MAKE A FUNCTION TO CHECK IF NUMBERS ARE REPEATED OR NOT, SHOULD BE EASY.

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
				printf("num[i]: '%d', detected to be = num[j]: '%d'\n",nums[i],nums[j]);
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
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + (str[i] - '0');
		if (((n * sign) > INT_MAX) || ((n * sign) < INT_MIN))
			return (-1);
		i++;
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
		if (super_atoi(av[i], &nums[i - 1]) == -1)
		{
			printf("atoi returned -1, num: '%s' not valid\n",av[i]);
			free(nums);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (nums);
}

int	main(int ac, char **av)
{
	int	*nums;
	int	size;

	if (ac <= 2)
	{
		printf("input more arguments\n");
		exit(EXIT_FAILURE);
	}
	nums = copy_args(av, nums);
	if (!nums)
	{
		printf("failure in copying\n");
		exit(EXIT_FAILURE);
	}
	size = get_total_nums(av);
	if (check_repeat(nums, size) == -1)
	{
		printf("numbers are repeated\n");
		free(nums);
		exit(EXIT_FAILURE);
	}
	print_array(nums, size);
	return (free(nums), 0);
}
