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

int cost_target(Node *targetNode, Node *stack, int size)
{
	int targetValue = targetNode->value;
	Node *current = stack;
	while (current)
	{
		if (targetValue == current->value)
			return (cost_topping(current, size));
		current = current->next;
	}
	return INT_MAX;
}

Node *cost_a2b(Queue *stack_a, Queue *stack_b)
{
	update_position(stack_a->head);
	update_position(stack_b->head);
	assign_targets(stack_a, stack_b, INT_MAX);
	Node *currentNode = stack_a->head;
	Node *targetNode = stack_b->head;
	int total_cost = INT_MAX;
	int cost_from_a = 0;
	int cost_target_b = 0;
	while (currentNode)
	{
		cost_from_a = cost_topping(currentNode, stack_a->size);
		cost_target_b = cost_target(currentNode->target, targetNode, stack_b->size);
		if (cost_from_a + cost_target_b < total_cost)
			total_cost = cost_from_a + cost_target_b;
		currentNode = currentNode->next;
	}
	return currentNode;
}

void run_algo(Queue *stack_a, Queue *stack_b, int counter)
{
	int n;
	n = counter + 3;
	Node *temp;

	(void)n;
	if (queue_is_sorted(stack_a, 0) && queue_is_empty(stack_b))
		return;
	else
	{
		if (stack_a->size == 3)
			return;
		else
		{
			if (stack_b->size <= 2)
				queue_push(stack_a, stack_b);
			else
				temp = cost_a2b(stack_a, stack_b);
			printf("%d-->%d\n", temp->value, temp->target->value);
		}
	} // run_algo(stack_a, stack_b, counter);
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
	run_algo(queue_A, queue_B, 0);
	printf("--QA--\n");
	print_queue(queue_A);
	printf("--QB--\n");
	print_queue(queue_B);

	printf("-----next_iter----\n");
	run_algo(queue_A, queue_B, 0);
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
	*/

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