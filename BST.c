#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"


struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* empty_bst() {
    return NULL;
}

struct node* make_node(int key) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->key = key;
    return new_node;
}


void insert_bst(struct node** tree, int num) {
    struct node* root = *tree;

    while (*tree != NULL) {
    
        if (num == (*tree)->key) {
            tree = &root; 
            return;
        }
        else if (num >= (*tree)->key) {
            tree = &(*tree)->right;
            
        }
        
        else {
            tree = &(*tree)->left;
        }
    }
    
    struct node* new_node = make_node(num);
    
    *tree = new_node;
    tree = &root; 
}


int search_bst(struct node* tree, int num) {
    struct node* t = tree;
    while (t != NULL) {
        if (t->key == num) {
            return 1;
        }
        else if (t->key < num) {
            t = t->right;
        }
        else {
            t = t->left;
        }
    }
    return 0;
}

void adjust_node(struct node* parent, struct node* cur, int r) {
    if(r == 1) {
        parent->right = cur;
    }
    else {
        parent->left = cur;
    }
}



void delete_bst(struct node* tree, int num) {
    if (tree == NULL) {
        return;
    }
    struct node* root = tree;
    struct node* parent = NULL;
    
    int right;
    while  (tree != NULL) {
        if (tree->key < num) {
            
            parent = tree;  
            right = 1;
            tree = tree->right;
        }
        else if (num < tree->key) {
            parent = tree;  
            right = 0;
            tree = tree->left;
        }
        else {
            if ((tree->right == NULL) && (tree->left == NULL)) {
                printf("here\n");
                adjust_node(parent, NULL, right);
                free(tree);
                tree = root;
                return;
            }
            else if (tree->right == NULL) {
                adjust_node(parent, tree->left, right);
                free(tree);
                tree = root;
                return;
            }
            else if (tree->left == NULL) {
                adjust_node(parent, tree->right, right);
                free(tree);
                tree = root;
                return;
            }
            else {
                struct node* rightmost = tree->left;
                struct node* temp;
                while (rightmost->right != NULL) {
                    parent = rightmost;
                    rightmost = rightmost->right;
                }

                tree->key = rightmost->key;

                if (rightmost->left == NULL) {
                    adjust_node(parent, NULL, 1);
                    free(rightmost);
                    tree = root;
                    return;
                }
                else {
                    adjust_node(parent, rightmost->left, 1);
                    rightmost = rightmost->left;
                    free(rightmost);
                    tree = root;
                    return;
                }
            }
        }
    }
}

struct lnode* bst_to_list(struct node* t) {
    struct lnode* res = NULL;
    struct node* root = t;
    struct node* pred;
    while (t != NULL) {
        if(t->left == NULL) {
            printf("%d\n", t->key);
            res = cons(t->key, res);
            t = t->right;
            
        }
        else {
            root = t;
            t = t->left;
            while((t->right != NULL) && (t->right != root)) {
                t = t->right;
            }
            if (t->right == NULL) {
                t->right = root;
                t = root->left;
            }
            else {
                printf("%d\n", root->key);
                res = cons(root->key, res);
                t->right = NULL;
                t = root->right;
            }
        }
    }
    return reverse_list(res);

}

int main() {
    
    struct node* a = malloc(sizeof(struct node));
    struct node* r = malloc(sizeof(struct node));
    r->key = 99;
    r->right = NULL;
    r->left = NULL;
    a->key = 10;
    a->right = r;
    a->left = NULL;
    // printf("%d\n", search_bst(r, 99));
    // delete_bst(a, 10);
    // printf("%d\n", search_bst(a, 99));
    
    struct node* test;
    int history[100];
    int random;
    for(int i = 0; i < 100; i++) {
        random = rand() % 1000;
        insert_bst(&test, random);
        history[i] = random;
    }
    struct lnode* q = bst_to_list(test);
    
    print_list(q);
    // printf("%d \n", test->key);
    // for(int i = 0; i < 100; i++) {
    //     int n = history[i];
    //     if (n != (test->key)) {
    //         delete_bst(test, n);
    //     }
    // }



    return 0;
}


