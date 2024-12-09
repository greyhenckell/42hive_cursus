#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct Node_s
{
    int value;
    struct Node_s *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} Queue;

int contain_digit(char *str);

// rules
void queue_swap(Queue *stack);
void queue_rotate(Queue *stack);
void queue_push(Queue *origin, Queue *dest);

// utils
Node *new_node(int value);
Queue *create_queue();
int queue_is_empty(Queue *queue);
void enqueue(Queue *queue, int value);
int check_item_queue(Queue *table, int item);

#endif