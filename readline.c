#include <stdlib.h>
#include <stdio.h>


struct node {
    char val;
    struct node* next; 
};

struct node* empty_list() {
    return NULL;
}

struct node* cons(char c, struct node* l) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = c;
    new_node->next = l;
    return new_node;
}

char* my_readline() {
    char c;
    int size = 0;
    struct node* list = empty_list();
    
    while ((c = getchar()) != EOF) {
        size++;
        list = cons(c, list);
    }
    char* res = malloc(sizeof(char) * (size + 1));
    printf("%d\n", size);
    for (int i = 1; i <= size; i++) {
        res[size - i] = list->val;
        list = list->next;
    }
    res[size+1] = '\0';
    return res;
}

int main() {
    // my_readline2();
    char *c = my_readline();
    printf("%s", c);

    return 0;
}