#include <stdio.h>
#include <stdlib.h>


// Written according to 
// Volume 1 of Art of Computer Programming
// Donald Knuth



struct Node {
    int key;
    struct Node* next;
};

struct Node* empty_list = NULL;

struct Node* make_node(int n) {
    struct Node *l = malloc(sizeof(struct Node));
    l->key = n;
    l->next = l;
    return l;
}

struct Node* insert_left(int n, struct Node *l) {
    if(l == NULL) {
        return make_node(n);
    }
    else {
        struct Node *nl = make_node(n);
        nl->next = l->next;
        l->next = nl;
        return l;
    }
}

struct Node* insert_right(int n, struct Node *l) {
    if(l == NULL) {
        return make_node(n);
    }
    else {
        struct Node* tmp = insert_left(n, l);
        return tmp->next;
    }
}

void print_list(struct Node *l) {
    if (l == NULL) {
        printf("NULL");
        return;
    }

    struct Node *last = l;
    l = l->next;
    while (l != last) {
        printf("%d ", l->key);
        l = l->next;
    }
    printf("%d ", l->key);
}

struct Node* pop(struct Node *l, int *n) {
    if(l == NULL) {
        exit(EXIT_FAILURE);
        return NULL;
    }
    
    else {
        struct Node* first = l->next;
        *n = first->key;
        if(first == l) {
            l = NULL;
        }
        else {
            l->next = first->next;
        }
        free(first);
        return l;

    }
 }


void free_list(struct Node* l) {
    if(l == NULL) return;
    struct Node *tmp;
    struct Node *last = l;
    l = l->next;
    while(l != last) {
        tmp = l->next;
        free(l);
        l = tmp;
    }
    free(last);
    return;
}

struct Node* append_list(struct Node* l, struct Node* ll) {
    if (l == NULL) return ll;
    else if (ll == NULL) return l;
    else {
        struct Node* first = l->next;
        l->next = ll->next;
        ll->next = first;
        return ll;
    }
}


int main() {
    struct Node *t = insert_right(3, insert_right(2, insert_right(1, NULL)));
    struct Node *r = insert_right(6, insert_right(5, insert_right(4, NULL)));
    // struct Node *t = insert_right(10, insert_right(20, NULL));
    // struct Node *t = insert_right(20, NULL);
    // free_list(t);
    // printf("%d\n", (t->key));
    // int *m;
    // t = pop(t, m);
    // t = pop(t,m);
    // t=pop(t, m);
    
    print_list(append_list(t, r));

}