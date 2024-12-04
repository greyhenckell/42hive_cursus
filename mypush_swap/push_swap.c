#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	print_array(int *table, int items)
{
	int	i;

	i = 0;
	while (i < items)
	{
		printf("--%d\n", (table[i]));
		i++;
	}
}

void	run_algo(int *table, int items)
{
	int	col;

	col = 1;
	// int flag = 0;
	// checking max:
	while (col < items && table[0] > table[col])
	{
		// check_sa(table, col, &flag);
		// printf("--%d\n", table[col]);
		col++;
	}
	if (col == items)
	    printf("%d is max", table[0]);
	else 
        printf("no max\n");
	// if (flag)
	//    run_algo(table, items);
}
// 30 10 20 5
// 10 30 20 5
// check if my peek is max
// run_algo(table, items);
// print_array(table, items);
// run from begining until pos
// check if exists > 1
int	check_duplicate(char **str, int input_len)
{
	int	temp[input_len];
	int	item;
	int	i;
	int	idx;

	// ["2", "30", "40"]
	// lst = (int **)malloc(sizeof(int *) * input_len);
	i = 1;
	idx = 0;
	while (i < input_len)
	{
		// printf("parsing:%s\n", str[i]);
		if (contain_digit(str[i]))
		{
			item = ft_atoi(str[i]);
			// printf("%d\n", item);
			if (check_item(temp, item) == 0)
			{
				temp[idx] = item;
				idx++;
			}
		}
		else
			return (0);
		i++;
	}
	// here is my stack :TEMP
	// printf("%d\n", idx);
	run_algo(temp, idx);
	// print_array(temp, idx);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		if (argc == 2)
			printf("check to split\n");
		else
		{
			if (!check_duplicate(argv, argc))
			{
				printf("error\n");
				return (1);
			}
		}
	else
	{
		printf("Error\n");
		return (1);
	}
}