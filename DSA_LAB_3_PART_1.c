#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform preorder traversal
void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;        // Visit root
    preorder(root->left, result, index);   // Traverse left subtree
    preorder(root->right, result, index);  // Traverse right subtree
}

// Main function to return preorder traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(3 * sizeof(int));  // Allocate space for 3 nodes
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}

int main() {
    // Create nodes
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    // Set node values
    root->val = 1;
    node2->val = 2;
    node3->val = 3;

    // Build the tree structure
    root->left = NULL;
    root->right = node2;
    node2->left = node3;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;

    // Perform preorder traversal
    int returnSize;
    int* result = preorderTraversal(root, &returnSize);

    // Print the result
    printf("Preorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(root);
    free(node2);
    free(node3);
    free(result);

    return 0;
}

