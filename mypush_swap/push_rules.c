#include "push_swap.h"
#include "libft/libft.h"

void queue_rotate(Queue *stack, int list)
{
    if (queue_is_empty(stack))
        return;
    Node *nodetemp = stack->head;
    stack->head = stack->head->next;
    nodetemp->next = NULL;

    stack->tail->next = nodetemp;
    nodetemp->prev = stack->tail;
    stack->tail = nodetemp;
    if (list == 1)
        write(1, "rb\n", 3);
    if (list == 0)
        write(1, "ra\n", 3);
}

void queue_rr(Queue *stack_a, Queue *stack_b)
{
    queue_rotate(stack_a, 2);
    queue_rotate(stack_b, 2);
    write(1, "rr\n", 3);
}

void queue_reverse_hook(Queue *stack)
{
    if (queue_is_empty(stack) || stack->size == 1)
        return;
    Node *nodetemp = stack->tail;
    stack->tail = nodetemp->prev;
    stack->tail->next = NULL;

    nodetemp->prev = NULL;
    nodetemp->next = stack->head;
    stack->head->prev = nodetemp;
    stack->head = nodetemp;
}

void queue_push(Queue *origin, Queue *dest, int stack)
{
    if (queue_is_empty(origin))
        return;
    Node *nodetemp = origin->head;
    enqueue(dest, nodetemp->value);

    origin->head = origin->head->next;
    free(nodetemp);
    origin->size--;
    queue_reverse_hook(dest);
    // dest->size++;
    if (stack)
        write(1, "pa\n", 3);
    else
        write(1, "pb\n", 3);
}

void queue_swap(Queue *stack, int origin)
{
    if (queue_is_empty(stack) || stack->head->next == NULL)
        return;

    int temp;

    temp = stack->head->value;
    stack->head->value = stack->head->next->value;
    stack->head->next->value = temp;
    if (origin == 0)
        write(1, "sa\n", 3);
    if (origin == 1)
        write(1, "sb\n", 3);
}

void queue_ss(Queue *stack_a, Queue *stack_b)
{
    queue_swap(stack_a, 2);
    queue_swap(stack_b, 2);
    write(1, "ss\n", 3);
}
void queue_reverse_rotate(Queue *stack, int origin)
{
    if (queue_is_empty(stack) || stack->size == 1)
        return;
    Node *nodetemp = stack->tail;
    stack->tail = nodetemp->prev;
    stack->tail->next = NULL;

    nodetemp->prev = NULL;
    nodetemp->next = stack->head;
    stack->head->prev = nodetemp;
    stack->head = nodetemp;
    if (origin == 1)
        write(1, "rrb\n", 4);
    if (origin == 0)
        write(1, "rra\n", 4);
}

void queue_rrr(Queue *stack_a, Queue *stack_b)
{
    queue_reverse_rotate(stack_a, 3);
    queue_reverse_rotate(stack_b, 3);
    write(1, "rrr\n", 4);
}