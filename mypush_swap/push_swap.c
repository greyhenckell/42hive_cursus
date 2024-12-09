#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void print_array(int *table, int items)
{
	int i;

	i = 0;
	while (i < items)
	{
		printf("--%d\n", (table[i]));
		i++;
	}
}

void print_queue(Queue *table)
{
	Node *current_item;

	current_item = table->head;
	while (current_item)
	{
		printf("%d\n", current_item->value);
		current_item = current_item->next;
	}
}

int peek_is_max(int *table, int items)
{
	int col;
	col = 1;
	while (col < items && table[0] > table[col])
		col++;
	if (col == items)
		return (1);
	return (0);
}

void run_algo(int *table, int *stack_b, int items)
{
	// int stack_b[items];
	// int idx_b = items;
	int i = 0;
	if (peek_is_max(table, items) && items > 2)
	{
		printf("ra\n");
		check_rotate(table, items);
		run_algo(table, stack_b, items - 1);
	}
	else
	{
		printf("no max %d\n", table[0]);
		if (table[i] < table[i + 1])
			check_push(stack_b, items, table[i]);
		else
		{
			printf("swap\n");
			check_swap(table);
			check_push(stack_b, items, table[i]);
			// run_algo(table, stack_b, items);
		}
	}
}

int check_duplicate(char **str, int input_len)
{
	int item;
	int i;

	Queue *queue_A = create_queue();
	Queue *queue_B = create_queue();

	i = 1;

	while (i < input_len)
	{
		if (contain_digit(str[i]))
		{
			item = ft_atoi(str[i]);
			// printf("%d\n", item);
			if (check_item_queue(queue_A, item) == 0)
				enqueue(queue_A, item);
		}
		else
			return (0);
		i++;
	}

	// queue_rotate(queue_A);
	printf("--QA--\n");
	print_queue(queue_A);
	/*queue_push(queue_A, queue_B);
	// printf("size:%d\n", queue_A->size);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);
	// printf("size:%d\n", queue_B->size);
	queue_swap(queue_A);
	printf("--QA--\n");
	print_queue(queue_A);*/

	return (1);
}

int main(int argc, char **argv)
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