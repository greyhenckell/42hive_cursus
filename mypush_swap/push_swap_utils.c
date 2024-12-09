#include "libft/libft.h"
#include "push_swap.h"

int contain_digit(char *str)
{
    int i = 0;
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
    return stack->head->value;
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
            if (currentNode->value > currentNode->next->value)
                return (0);
            currentNode = currentNode->next;
        }
        return (1);
    }
    else
    {
        currentNode = stack->tail;
        while (currentNode && currentNode->prev != NULL)
        {
            if (currentNode->value > currentNode->prev->value)
                return (0);
            currentNode = currentNode->prev;
        }
        return (1);
    }
}

int peek_is_max(Queue *stack)
{
    if (queue_is_empty(stack))
        return 0;
    Node *peakNode;
    peakNode = stack->head;

    Node *currentNode = stack->head->next;
    while (currentNode)
    {
        if (peakNode->value < currentNode->value)
            return (0);
        currentNode = currentNode->next;
    }
    return (1);
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
    newNode->next = NULL;
    newNode->prev = NULL;

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
