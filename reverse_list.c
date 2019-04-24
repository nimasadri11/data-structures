#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* return_val = head;
    struct ListNode* before = NULL;
    
    for(int i = 1; i <= m; i++) {
        before = head;
        head = head->next;
    }
    
    printf("first done\n");
    
    struct ListNode* temp = head;
    for(int j = m; (j < n) && (temp != NULL); j++) {
        printf("%d \n", head->val);
        temp = head->next;
        head->next = before;
        before = head;
        head = temp; 

    }
    printf("second done\n");
    printf("eofunction: %d\n", ((return_val->next)->next)->val);
    
    
    return return_val;
    
}

int main() {
    struct ListNode* a = malloc(sizeof(struct ListNode));
    struct ListNode* b = malloc(sizeof(struct ListNode));
    struct ListNode* c = malloc(sizeof(struct ListNode));
    struct ListNode* d = malloc(sizeof(struct ListNode));
    a->val = 1;
    a->next = b;
    b->val = 2; 
    b->next = c;
    c->val = 3; c->next = d; d->val = 4; d->next = NULL;
    // [1, 2, 3, 4] --> [1, 3, 2, 4]
    struct ListNode* new = reverseBetween(a, 2, 3);
    for(int i = 0; i < 4; i++) {
        printf("%d \n", new->val);
        new = new->next;
    }
    return 0;
}