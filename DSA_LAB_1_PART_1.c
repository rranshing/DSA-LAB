#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;
    
    struct ListNode* ptr = temp;

    
    while (ptr->next != NULL) {
        if (ptr->next->val == val) {
            struct ListNode* toDelete = ptr->next;
            ptr->next = ptr->next->next;
            free(toDelete);  
        } else {
            ptr = ptr->next;
        }
    }
    
    
    struct ListNode* newHead = temp->next;
    free(temp);  

    return newHead;
}


void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(4);

    printf("Original list: ");
    printList(head);

    int valToRemove = 6;
    head = removeElements(head, valToRemove);

    printf("List after removing %d: ", valToRemove);
    printList(head);

   
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

