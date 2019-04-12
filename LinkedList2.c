#include <stdio.h>
#include <stdlib.h>
#include "LinkedList2.h"

void Init_DL(List *list) {
    list->head = (Node *) malloc(sizeof(Node));
    list->tail = (Node *) malloc(sizeof(Node));

    list->head->prev = NULL;
    list->head->next = list->tail;

    list->tail->next = NULL;
    list->tail->prev = list->head;

    list->size = 0;
}

int isEmpty(List *list) {
    return !(list->size) ? 1 : 0;
}

int getSize(List *list) {
    return list->size;
}

void Insert(List *list, int pos, Item item) {
    if (pos < 1 || pos > getSize(list) + 1) {
        printf("Out of range!\n");
    } else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = item;
        Node *p = list->head;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        new_node->next = p->next;
        p->next->prev = new_node;
        p->next = new_node;
        new_node->prev = p;
        list->size++;
    }
}

void Display(List *list) {
    if (isEmpty(list)) {
        printf("list is empty!\n");
    } else {
        Node *p = list->head->next;
        for (int i = 1; p != list->tail; i++) {
            printf("List[%d] : %c\n", i, p->data);
            p = p->next;
        }
    }
}

void Delete(List *list, int pos) {
    if (isEmpty(list)) {
        printf("list is empty!\n");
    } else if (pos < 1 || pos > getSize(list) + 1) {
        printf("Out of range!\n");
    } else {
        Node *del = list->head->next;

        for (int i = 0; i < pos - 1; i++) {
            del = del->next;
        }

        del->prev->next = del->next;
        del->next->prev = del->prev;

        free(del);
        list->size--;
    }
}

Item Retrieve(List *list, int pos) {
    if (isEmpty(list)) {
        printf("Empty\n");
    } else if (pos < 1 || pos > getSize(list)) {
        printf("Out of range\n");
    } else {
        Node *ptr = list->head;
        for (int i = 0; i < pos; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    }
    return fprintf(stderr, "error");
}

void Display_R(List *list) {
    if (isEmpty(list)) {
        printf("Empty\n");
    } else {
        Node *p = list->tail->prev;
        for (int i = getSize(list); p != list->head; i--) {
            printf("List[%d] : %c\n", i, p->data);
            p = p->prev;
        }
    }
}

void Init_CDL(List *list) {
    list->head = (Node *) malloc(sizeof(Node));
    list->tail = (Node *) malloc(sizeof(Node));

    list->head->prev = list->tail;
    list->head->next = list->tail;

    list->tail->next = list->head;
    list->tail->prev = list->head;

    list->size = 0;
}

void Display_T(List *list, int times) {
    if (isEmpty(list)) {
        printf("Empty!\n");
    } else {
        Node *p = list->head;
        for (int i = 0; i < times;) {
            if (p == list->head || p == list->tail) {
                p = p->next;
                continue;
            }
            printf("%c ", p->data);
            p = p->next;
            i++;
        }
    }
    printf("\n");
}

void Delete_all(List *list) {
    Node *p = list->head->next;
    while (p != list->tail) {
        Node *del = p;
        p = p->next;
        printf("'%c' deleted\n", del->data);
        free(del);
    }
    free(list->head);
    free(list->tail);
    printf("'Head & Tail' node deleted\n");
}

// f(n,k) = ((f(n,k) + k) + k) mod n
void Josephus(List *list, int n, int m) {
    int curr = m - 1;

    printf("<< ");
    for (int i = 0; i < n; i++) {
        Node *ptr = list->head->next;
        for (int j = 0; j < curr; j++) {
            ptr = ptr->next;
        }
        printf("%c ", ptr->data);

        Delete(list, curr + 1);

        curr += m - 1; // (f(n,k) + k) + k
        if (getSize(list) > 0) {
            curr %= getSize(list); // mod n
        }
    }
    printf(">>\n");
}