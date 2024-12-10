#include "push_swap.h"

void queue_rotate(Queue *stack)
{
    if (queue_is_empty(stack))
        return;
    Node *nodetemp = stack->head;
    stack->head = stack->head->next;
    nodetemp->next = NULL;

    stack->tail->next = nodetemp;
    stack->tail = nodetemp;
}

void queue_push(Queue *origin, Queue *dest)
{
    if (queue_is_empty(origin))
        return;
    Node *nodetemp = origin->head;
    enqueue(dest, nodetemp->value);

    origin->head = origin->head->next;
    free(nodetemp);
    origin->size--;
}

void queue_swap(Queue *stack)
{
    if (queue_is_empty(stack) || stack->head->next == NULL)
        return;
    Node *firstNode = stack->head;
    Node *secondNode = stack->head->next;

    firstNode->next = secondNode->next;
    secondNode->next = firstNode;

    stack->head = secondNode;
}
void queue_reverse_rotate(Queue *stack)
{
    if(queue_is_empty(stack) || stack->size == 1)
        return;
    Node *nodetemp = stack->tail;
    stack->tail = nodetemp->prev;
    stack->tail->next = NULL;

    nodetemp->prev = NULL;
    nodetemp->next = stack->head;
    stack->head->prev = nodetemp;
    stack->head = nodetemp;
}