#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node* bef;
    struct node* next;
    int val;
};

struct node* empty_list() {
    return NULL;
}



struct node* cons(int n, struct node* l) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = n;
    new_node->next = l;
    if(l == NULL) {
        new_node->next = new_node;
        new_node->bef = new_node;
        return new_node;

    }
    else {
        new_node->bef  = l->bef;
        l->bef = new_node;
        return new_node;
    }

}


// int main() {
//     struct node* r = cons(4, cons(3, cons(2, empty_list())));
//     printf("%d\n", (r->next)->val);
//     return 0;
// }
