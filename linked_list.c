#include <stdio.h>
#include <stdlib.h>

struct lnode {
    int key;
    struct lnode* next;
};

struct lnode* cons(int n, struct lnode* l) {
    struct lnode* new = malloc(sizeof(struct lnode));
    new->key = n;
    new->next = l;
    return new;
}

// return the first element of the list
int car(struct lnode* l) {
    return l->key;
} 


// This function MUTATES the original list
// frees the first element
// the result points to the "next" field
void cdr(struct lnode* l) {
    struct lnode* temp = l;
    l = l->next;
    free(temp);
} 

struct lnode* reverse_list(struct lnode* l) {
    struct lnode* temp;
    struct lnode* before = NULL;
    while(l->next != NULL) {
        temp = l->next;
        l->next = before;
        before = l;
        l = temp;
    }
    l->next = before;
    return l;
    
}


void print_list(struct lnode* l) {
    printf("[");
    if(l != NULL) {
        while(l->next != NULL) {
            printf("%d, ", l->key);
            l = l->next;
        }
        printf("%d", l->key);
    }
    printf("]\n");
    return;
}


// struct lnode* even_odd_list(struct lnode* l) {

//     struct lnode* even = malloc(sizeof(struct lnode));
//     struct lnode* odd = malloc(sizeof(struct lnode));
//     if (!l) return l;
//     struct lnode* ll = l->next;
//     // struct
//     int even_odd = 1; 
//     while(ll != NULL) {
//         if (ll->next == NULL) {
//             if(even_odd == 1) {
//                 odd 
//             }
//         }
//     }




// }



// int main() {
//     int* a = malloc(sizeof(int));
//     *a = 22;
//     free(a);
//     int *c = malloc(sizeof(int));
//     *c = 69;
//     int b = *a;
//     printf("%d\n", b);

//     return 0;
// }

