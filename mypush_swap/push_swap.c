#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	print_queue(Queue *table)
{
	Node	*current_item;

	current_item = table->head;
	while (current_item)
	{
		printf("%d\n", current_item->value);
		current_item = current_item->next;
	}
}

void	run_algo(Queue *stack_a, Queue *stack_b)
{
	if (queue_is_sorted(stack_a, 0) && queue_is_empty(stack_b))
		return ;
	else
	{
		
		if (peek_is_max(stack_a))
		{
			queue_rotate(stack_a);
			run_algo(stack_a, stack_b);
		}
		else
		{
			queue_push(stack_a, stack_b);
			if(stack_b->size >= 2)
			{
				if (!queue_is_sorted(stack_b,1))
				{
					queue_swap(stack_b);					
				}
				else
				{
					if(queue_is_sorted(stack_a,0))
						queue_push(stack_b, stack_a);
				}
			}
			if (!queue_is_sorted(stack_a,0))
			{
				queue_push(stack_a, stack_b);				
			}
			//queue_reverse_rotate(stack_a);
						
		}
	}
	run_algo(stack_a, stack_b);
}

int	check_duplicate(char **str, int input_len)
{
	int		item;
	int		i;
	Queue	*queue_A;
	Queue	*queue_B;

	queue_A = create_queue();
	queue_B = create_queue();
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
	run_algo(queue_A, queue_B);
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);
	//queue_reverse_rotate(queue_A);
	
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