#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"

void remove_test(Node *, int);

int main(void) {
    Node * head = make_list();
    if (head == NULL) {
        printf("Not enough memory for a list");
        return 0;
    }
    for (char c = 'a' ; c <= 'z'; c++) {
        if (!add_node(head, c))
            printf("Failed to add '%c' to the list.\n", c);
    }
    print_list(head);
    remove_test(head, 1);
    remove_test(head, 0);
    print_list(head);
    destroy_list(head);
    head = NULL;
    printf("add node to null list behaves as expected: %s\n", add_node(head, 'a') ? "failed" : "success");
    print_list(head);
    return 0;
}

void remove_test(Node *head, int index) {
    printf("Removing %d: %s.\n", index, remove_node(head, index) ? "passed" : "failed");
}
