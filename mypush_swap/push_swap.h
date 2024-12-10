#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct Node_s
{
    int value;
    struct Node_s *next;
    struct Node_s *prev;
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
void queue_reverse_rotate(Queue *stack);

// utils
Node *new_node(int value);
Queue *create_queue();
int queue_is_empty(Queue *queue);
void enqueue(Queue *queue, int value);
int check_item_queue(Queue *table, int item);
int queue_is_sorted(Queue *stack, int reverse);
int get_peak(Queue *stack);
int peek_is_max(Queue *stack);

#endif