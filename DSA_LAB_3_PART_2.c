#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to do inorder traversal
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    inorder(root->left, result, index);       // Traverse left
    result[(*index)++] = root->val;           // Visit root
    inorder(root->right, result, index);      // Traverse right
}

// Main function to be called
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));  // Max 100 nodes
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}


int main() {
    

    // Allocate nodes
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));

    // Assign values
    root->val = 1;
    node2->val = 2;
    node3->val = 3;

    // Connect nodes
    root->left = NULL;
    root->right = node2;
    node2->left = node3;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;

    // Traverse
    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    // Print result
    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free memory
    free(root);
    free(node2);
    free(node3);
    free(result);

    return 0;
}
