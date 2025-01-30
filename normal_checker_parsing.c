#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//THIS WAS AN ATTEMPT, MIGHT COME BACK TO IT, NOW GONNA TRY TO DO IT WITHOUT
//USING A CHECKER FUNCTION, DIRECTLY PARSING THE ARGS (SIGNS, OTHER CHARS,
//OVER MAX/MIN NUMS) IN A REPURPOSED ATOI FUNCTION, THAT ALSO RETURNS THE NUMBERS
//IN AN ARRAY OF INTS, MIGHT BE TOO CRAZY AND HARD TO IMPLEMENT, BUT WE WILL SEE.

//INVALID ARGS ARE PROPERLY CHECKED (AT LEAST THE CASES I KNOW), IM MISSING THE REST
//OF THE PARSING NOW.

//NEED TO CHECK IF NUMBERS ARE ABOVE/BELOW MAX/MIN INT, DO THIS BY USING THE ATOI
//FUNCTION, IT AUTOMATICALLY CHECKS THE MAX AND MIN, AND EXITS IF ITS INVALID.

//ALSO NEED TO CHECK IF NUMBERS ARE REPEATED, ITERATE EACH NUMBER AS IF IT WAS AN
//INTER FUNCTION. DO AN STRNCMP OF THE ENTIRE STRING WITH EACH NUMBER.

//MISSING ENTIRETY OF INSERTING NUMBERS INSIDE A LIST, THEORETICALLY NUMBERS ARE
//EXTRACTED USING A SPLIT THAT CREATES AN ARRAY WHERE EVERY STRING IS JUST ONE NUMBER
//AN ITS SIGN, THEN A FUNCTION WILL MAKE AN ITOA OF EACH NUMBER AND THEN ADD THE
//RESULT TO THE CURRENT NODE OF THE LIST.

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue;
			}
			if ((av[i][j] == '+' || av[i][j] == '-') &&
				(j == 0 || av[i][j - 1] == ' ') &&
				(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
			{
				j++;
				continue;
			}
			if ((av[i][j] < '0' || av[i][j] > '9'))
			{
				printf("args invalid\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	*large_append(char **av)
{
	char	*dst;
	int	i;
	int	j;

	i = 0;
	j = 0;

}

/*
int	get_total_num(char **argv)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				total++;
				j++;
				continue;
			}
			while (argv[i][j] >= '0' && argv[i][j] <= '9' && argv[i][j])
			{
				total++;
				j++;
			}
			if (argv[i][j] == ' ' || argv[i][j] == '\0')
			{
				if (argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9')
					total++;
			}
		}
		i++;
	}
	return (total);
}

char	*nums_copy(char **argv, char *dst)
{
	int	i;
	int	j;
	int	di;

	i = 1;
	j = 0;
	di = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' && argv[i][j])
				j++;
			if ((i != 1 || j != 0) && dst[di - 1] != ' ')
			{
				dst[di] = ' ';
				di++;
			}
			while ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j]
				&& (argv[i][j] != '-' && argv[i][j] != '+'))
				j++;
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				dst[di] = argv[i][j];
				di++;
				j++;
			}
			while ((argv[i][j] >= '0' && argv[i][j] <= '9')
				&& argv[i][j])
			{
				dst[di] = argv[i][j];
				di++;
				j++;
			}
		}
		if (argv[i + 1])
		{
			dst[di] = ' ';
			di++;
		}
		i++;
	}
	dst[di] = '\0';
	return (dst);
}*/

int	main(int ac, char **av)
{
	char	*nums;
	//int	total_num;

	if (check_args(av) == -1)
		exit(EXIT_FAILURE);
	nums = large_append(av);
	if (!nums)
		exit(EXIT_FAILURE);
	printf("nums: '%s'\n",nums);
	/*total_num = get_total_num(argv);
	printf("totalnum: '%d'\n",total_num);
	nums = (char *)malloc((total_num) * sizeof(char));
	if (!nums)
		return (0);
	nums = nums_copy(argv, nums);
	printf("nums: '%s'\nlen of nums: '%ld'\n",nums,strlen(nums));*/
}
