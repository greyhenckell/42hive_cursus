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
        queue_push(stack_a, stack_b, 0);
    else
    {
        // if( stack_b->size>1 && queue_is_sorted(stack_b,1))
        //	return;

        if (get_peak(stack_a) > get_peak(stack_b))
            queue_push(stack_a, stack_b, 0);
        else
        {
            queue_push(stack_a, stack_b, 0);
            queue_rotate(stack_b, 1);
        }
    }
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

void sort_three_items(Queue *stack)
{
    if (queue_is_sorted(stack, 0))
        return;
    else
    {
        if (peek_is_max(stack->head))
            queue_rotate(stack, 0);
        else if (stack->head->value > stack->head->next->value)
            queue_swap(stack, 0);
        else
            queue_reverse_rotate(stack, 0);
    }
    sort_three_items(stack);
}

void sort_five(Queue *stack_a, Queue *stack_b, int median)
{
    Node *head_ptr = stack_a->head;
    int med_dist = INT_MAX;
    int temp;

    while (head_ptr)
    {
        temp = (head_ptr->value - median);
        if (temp < 0)
            temp *= -1;
        if (temp < med_dist)
        {
            med_dist = temp;
            stack_a->med = head_ptr->value;
        }
        head_ptr = head_ptr->next;
    }
    head_ptr = stack_a->head;
    int size = stack_a->size;
    printf("med:%d sizeB:%d\n", stack_a->med, stack_b->size);
    int pos = 0;
    while (pos <= size - 1)
    {
        if (stack_a->size == 3)
            break;
        if (get_peak(stack_a) < stack_a->med)
            queue_push(stack_a, stack_b, 0);
        else
            queue_rotate(stack_a, 0);
        pos++;
    }
    if (stack_a->size == 3)
        sort_three_items(stack_a);
    if (queue_is_sorted(stack_a, 0) && !queue_is_sorted(stack_b, 1))
    {
        if (is_tail_max(stack_b->tail) && stack_b->tail->value > stack_a->head->value)
        {
            queue_rr(stack_a, stack_b);
            queue_push(stack_b, stack_a, 1);
        }
        else
            queue_push(stack_b, stack_a, 1);
    }
    if (is_tail_min(stack_a->tail))
        queue_reverse_rotate(stack_a, 0);

    if (stack_b->size > 1)
    {
        if (peek_is_max(stack_a->head->next) && is_tail_max(stack_b->tail))
            queue_rrr(stack_a, stack_b);
        if (peek_is_max(stack_a->head) && peek_is_min(stack_b->head))
            queue_rr(stack_a, stack_b);
        if (peek_is_max(stack_b->head))
            queue_push(stack_b, stack_a, 1);
    }

    if (stack_b->size == 1)
        queue_push(stack_b, stack_a, 1);
    if (!queue_is_sorted(stack_a, 0))
        queue_swap(stack_a, 0);
}

void push_back(Queue *stack_a, Queue *stack_b)
{
    if (queue_is_sorted(stack_a, 0) && stack_b->size == 0)
        return;
    else
    {
        if (!queue_is_sorted(stack_a, 0) && stack_a->size == 3)
            sort_three_items(stack_a);
        if (peek_is_max(stack_b->head))
            queue_push(stack_b, stack_a, 1);
        else
        {
            queue_swap(stack_b, 1);
            queue_push(stack_b, stack_a, 1);
        }
    }
    push_back(stack_a, stack_b);
}

void find_medium(Queue *stack_a, Queue *stack_b)
{
    int medium;
    medium = (stack_a->head->value + stack_a->tail->value) / 2;
    printf("med:%d\n", medium);
    if (stack_a->head->value > medium)
        queue_push(stack_a, stack_b, 0);
    else
        queue_rotate(stack_a, 0);
}

void run_algo(Queue *stack_a, Queue *stack_b, int median)
{

    if (queue_is_sorted(stack_a, 0) && queue_is_empty(stack_b))
        return;
    else
    {

        if (stack_a->size == 3)
            sort_three_items(stack_a);
        else if (stack_a->size == 5)
        {
            sort_five(stack_a, stack_b, median);
            // push_back(stack_a, stack_b);
        }
        else
        {

            printf("here");

            return;
        }
    } // run_algo(stack_a, stack_b, median);
}

int check_duplicate(char **str, int input_len)
{
    int item;
    int i;
    Queue *queue_A;
    Queue *queue_B;

    int maxValue = INT_MIN;
    int minValue = INT_MAX;

    queue_A = create_queue();
    queue_B = create_queue();
    i = 1;
    while (i < input_len)
    {
        if (contain_digit(str[i]))
        {
            item = ft_atoi(str[i]);
            if (item > maxValue)
                maxValue = item;
            if (item < minValue)
                minValue = item;
            if (check_item_queue(queue_A, item) == 0)
                enqueue(queue_A, item);
        }
        else
            return (0);
        i++;
    }
    //
    // printf("max:%d min:%d\n", maxValue, minValue, );
    printf("--INPUT--\n");
    print_queue(queue_A);
    printf("-----next_iter----\n");
    run_algo(queue_A, queue_B, (maxValue + minValue) / 2);
    printf("--QA--\n");
    print_queue(queue_A);
    printf("--QB--\n");
    print_queue(queue_B);

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