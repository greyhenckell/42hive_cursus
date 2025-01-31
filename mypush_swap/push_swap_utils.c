#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int contain_digit(char *str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return (1);
}

int get_peak(Queue *stack)
{
    if (queue_is_empty(stack))
        return (0);
    return stack->head->value;
}

int get_next_peak(Queue *stack)
{
    if (queue_is_empty(stack))
        return (0);
    return stack->head->next->value;
}

int queue_is_sorted(Queue *stack, int reverse)
{
    if (queue_is_empty(stack))
        return (0);
    Node *currentNode;
    if (reverse == 0)
    {
        currentNode = stack->head;
        while (currentNode && currentNode->next != NULL)
        {
            if (currentNode->value < currentNode->next->value)
                currentNode = currentNode->next;
            else
                return (0);
        }
        return (1);
    }
    else
    {
        currentNode = stack->tail;
        while (currentNode && currentNode->prev != NULL)
        {
            if (currentNode->value < currentNode->prev->value)
                currentNode = currentNode->prev;
            else
                return (0);
        }
        return (1);
    }
}

int peek_is_max(Node *node)
{
    if (!node)
        return 0;
    Node *peakNode;
    peakNode = node;
    Node *currentNode = node->next;
    while (currentNode)
    {
        if (peakNode->value < currentNode->value)
            return (0);
        currentNode = currentNode->next;
    }
    free(currentNode);
    return (1);
}

int peek_is_min(Node *node)
{
    if (!node)
        return 0;
    Node *peakNode;
    peakNode = node;
    Node *currentNode = node->next;
    while (currentNode)
    {
        if (peakNode->value > currentNode->value)
            return (0);
        currentNode = currentNode->next;
    }
    free(currentNode);
    return (1);
}

int is_tail_min(Node *node)
{
    if (!node)
        return 0;
    Node *tailNode;
    tailNode = node;

    Node *currentNode = node->prev;
    while (currentNode)
    {
        if (tailNode->value > currentNode->value)
            return (0);
        currentNode = currentNode->prev;
    }
    return (1);
}

int is_tail_max(Node *node)
{
    if (!node)
        return 0;
    Node *tailNode;
    tailNode = node;

    Node *currentNode = node->prev;
    while (currentNode->value != 0)
    {
        // printf("%d %d\n", tailNode->value, currentNode->value);
        if (tailNode->value < currentNode->value)
            return (0);
        currentNode = currentNode->prev;
    }
    return (1);
}

Node *find_target(int value, Node *currentNode, int limit)
{
    Node *head;
    Node *bestTarget;
    int min_distance = limit;
    int temp;

    bestTarget = 0;
    head = currentNode;
    while (head)
    {

        temp = head->value - value;
        if (temp < 0)
            temp *= -1;
        // printf("besttg:%d %d dist:%d tmp:%d\n", value, head->value, min_distance, temp);
        if (temp < min_distance && !(head->target))
        {

            bestTarget = head;
            min_distance = temp;
            head->target = head;
        }
        head = head->next;
    }
    if (!bestTarget)
    {
        head = currentNode;
        bestTarget = head;
        while (head)
        {
            if (head->value < bestTarget->value)
                bestTarget = head;
            head = head->next;
        }
    }
    return bestTarget;
}

void assign_targets(Queue *stack_a, Queue *stack_b, int limit)
{
    Node *current = stack_a->head;
    while (current)
    {

        current->target = find_target(current->value, stack_b->head, limit);
        current = current->next;
    }
}

void update_position(Node *stack)
{
    Node *currentNode = stack;
    int i = 0;
    while (currentNode)
    {
        currentNode->pos = i;
        currentNode = currentNode->next;
        i++;
    }
}

int cost_topping(Node *stack, int size)
{
    Node *currentNode = stack;
    if (currentNode->pos <= size / 2)
        return currentNode->pos;
    return (size - currentNode->pos);
}

int check_item_queue(Queue *table, int item)
{
    Node *currentNode;

    currentNode = table->head;
    while (currentNode)
    {
        if (currentNode->value == item)
            return (1);
        currentNode = currentNode->next;
    }
    return (0);
}

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    if (!queue)
        return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int queue_is_empty(Queue *queue)
{
    return (queue->head == NULL);
}

Node *new_node(int value)
{
    Node *newNode;

    newNode = malloc(sizeof(Node));
    if (!newNode)
        return NULL;
    newNode->value = value;
    newNode->pos = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->target = NULL;

    return newNode;
}

void enqueue(Queue *queue, int value)
{
    Node *newNode;

    newNode = new_node(value);
    if (queue_is_empty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        newNode->prev = queue->tail;
        queue->tail = newNode;
    }
    queue->size++;
}
