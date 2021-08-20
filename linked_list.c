#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"


struct node {
  char character;
  Node *next;
};

Node *make_list(void) { // makes head of list
  Node *head = (Node *)malloc(sizeof(Node));
  if (head != NULL) {
      head->character = '\0';
      head->next = NULL;
  }
  return head;
}

bool add_node(Node *head, char c) { // adds nodes to the list
    if (head == NULL) return false;
    Node *tracker = head;
    while (tracker->next) {
        tracker = tracker->next;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    //printf("trying to add node\n");
    if (!node) return false;
    tracker->next = node;
    node->character = c;
    node->next = NULL;
    return true;
}

char return_character(Node *head, int index) {
    if (head == NULL || index < 0) return '\0';
    Node *tracker = head->next;
    for (int i = 0; i < index; i++) {
        if (!tracker) return '\0';
        tracker = tracker->next;
    }
    return (tracker) ? tracker->character : '\0';
}

void print_list(Node *head) {
    if (head == NULL) return;
    Node *tracker = head->next;
    while (tracker) {
        //printf("%c\n", tracker->character);
        printf("%c", tracker->character);
        tracker = tracker->next;
    }
    printf("\n");
}

bool remove_node(Node *head, int index) {
    if (head == NULL || index < 0) return false;
    Node *tracker = head;
    for (int i = 0; i < index; i++) {
        if (!tracker->next) return false;
        tracker = tracker->next;
    }
    Node * temporary = tracker->next;
    tracker->next = tracker->next->next;
    free(temporary);
    return true;
}


bool destroy_list(Node *head) {
    if (head == NULL) return false;
    Node *temporary;
    while (head != NULL) {
        temporary = head->next;
        free(head);
        head = temporary;
    }
    return true;
}
