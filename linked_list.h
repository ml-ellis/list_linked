#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct node Node;

Node *make_list(void);

bool add_node(Node *, char);

char return_character(Node *, int);

void print_list(Node *);

bool remove_node(Node *, int);

bool destroy_list(Node *);

#endif
