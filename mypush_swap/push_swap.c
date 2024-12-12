#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

void push_position(Queue *stack_a, Queue *stack_b)
{
	if (queue_is_empty(stack_b))
		queue_push(stack_a, stack_b);
	else
	{
		// if( stack_b->size>1 && queue_is_sorted(stack_b,1))
		//	return;

		if (get_peak(stack_a) > get_peak(stack_b))
			queue_push(stack_a, stack_b);
		else
		{
			queue_push(stack_a, stack_b);
			queue_rotate(stack_b);
		}
	}
}

int check_status_b(Queue *stack)
{
	if (queue_is_empty(stack))
		return 0;
	if (queue_is_sorted(stack, 1))
		return 1;

	if (stack->size >= 2)
	{

		if (peek_is_min(get_peak(stack), stack->head->next))
		{
			queue_rotate(stack);
		}
		else if (peek_is_min(stack->head->next->value, stack->head->next->next))
		{
			queue_swap(stack);
			queue_rotate(stack);
		}
	}
	return 0;
}

int check_status_a(Queue *stack_a, Queue *stack_b)
{

	if (stack_a->size >= 2)
	{
		printf("push");
		if (peek_is_min(get_peak(stack_a), stack_a->head->next))
			queue_push(stack_a, stack_b);
		else if (peek_is_min(stack_a->head->next->value, stack_a->head->next->next))
		{
			queue_swap(stack_a);
			queue_push(stack_a, stack_b);
		}
		else
		{
			printf("push");
			queue_push(stack_a, stack_b);
		}
	}
	return 0;
}

void run_algo(Queue *stack_a, Queue *stack_b)
{

	if (queue_is_sorted(stack_a, 0) && queue_is_empty(stack_b))
		return;
	else
	{
		check_status_b(stack_b);
		if (stack_b->size <= 1)
			queue_push(stack_a, stack_b);
		else if (queue_is_sorted(stack_a, 0) && check_status_b(stack_b))
			queue_push(stack_b, stack_a);
		else if (peek_is_max(stack_a))
			queue_rotate(stack_a);
		else if (is_tail_min(stack_a))
		{
			queue_reverse_rotate(stack_a);
			queue_push(stack_a, stack_b);
		}
		else
			check_status_a(stack_a, stack_b);
	}
	// run_algo(stack_a, stack_b);
}

int check_duplicate(char **str, int input_len)
{
	int item;
	int i;
	Queue *queue_A;
	Queue *queue_B;

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
	//

	printf("--QA--\n");
	print_queue(queue_A);
	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	/*printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);
	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);*/

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