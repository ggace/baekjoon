#define true 1
#define false 0
typedef long long ll;
typedef unsigned long long ull;
typedef int bool;

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    struct _Node* next;
    int data;
} Node;

Node* Head;

void init() {
    Head = (Node*)malloc(sizeof(Node));
    
    Head->next = NULL;
    Head->data = 0;
}

Node* make_new_node(int val) {
    Node *node = (Node*) malloc(sizeof(Node));

    node->data = val;
    node->next = NULL;

    return node;
}

void push_back(int data) {
    if(Head == NULL) {
        return;
    }
    Node* node = Head;

    while(node->next != NULL) {
        node = node-> next;
    }

    node->next = make_new_node(data);
}

void push_front(int data){
    if(Head == NULL) {
        return;
    }
    Node* node = make_new_node(data);

    node->next = Head->next;

    Head->next = node;
}

int get(int n) {
    if(Head == NULL) {
        return 0;
    }
    Node* node = Head;
    for(int i = 0; i < n; i++) {
        if(node-> next == NULL) {
            
            return 0;
        }
        node = node->next;
    }

    return node->next->data;
}

void update(int n, int data) {
    if(Head == NULL) {
        return;
    }
    Node* node = Head;
    for(int i = 0; i < n; i++) {
        if(node-> next == NULL) {
            
            return;
        }
        node = node->next;
    }

    node->next->data = data;
}

void delete(int n) {
    if(Head == NULL) {
        return;
    }
    Node* node = Head;

    for(int i = 0; i < n; i++) {
        if(node-> next == NULL) {
            
            return;
        }
        node = node->next;
    }

    Node* del_node = node->next;

    node->next = del_node -> next;

    free(del_node);
}

int size() {
    if(Head == NULL) {
        return 0;
    }
    Node* node = Head;
    int cnt=0;

    while(node->next != NULL) {
        node = node-> next;
        cnt++;
    }

    return cnt;
}

void free_all() {

    if(Head == NULL) {
        return;
    }

    Node* free_node = Head->next;
    while(free_node->next != NULL) {
        Node* next_node = free_node -> next;
        free(free_node);
        free_node = next_node;
    }
}

void insert(int n, int data) {
    if(Head == NULL) {
        return;
    }
    if(n == 0) {
        push_front(data);
        return;
    }
    if(n == size()) {
        push_back(data);
        return;
    }
    Node* node = Head;
    for(int i = 0; i < n; i++) {
        if(node-> next == NULL) {
            break;
        }
        node = node->next;
    }

    Node* insert_node = make_new_node(data);

    Node* nxt = node->next;

    insert_node->next = nxt;
    node->next = insert_node;
}

void traverse() {
    Node* node = Head;
    while(node -> next != NULL) {
        node = node -> next;
        printf("%d\n", node->data);
    }
}

int main() {
    init();

    for(int i = 0; i < 15; i++) {
        push_front(i);
    }
    for(int i = 0; i < 15; i++) {
        push_back(i);
    }

    traverse();
    printf("\n");

    delete(0);

    traverse();
    printf("\n");

    free_all();
    free(Head);
    return 0;
}
