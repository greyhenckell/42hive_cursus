#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct Node_s
{
    int value;
    int pos;
    struct Node_s *next;
    struct Node_s *prev;
    struct Node_s *target;
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
int is_tail_min(Queue *stack);
int peek_is_min(int peak, Node *currentNode);
Node *find_target(int value, Node *currentNode, int limit);
void assign_targets(Queue *stack_a, Queue *stack_b, int limit);

void update_position(Node *stack);
int cost_topping(Node *stack, int size);

int is_tail_max(Queue *stack);

#endif