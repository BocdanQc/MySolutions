/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond with ChatGPT
//
// Description: C++ solution to implement a binary search tree class.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val) {
        if (node == NULL) return new TreeNode(val);
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int val) {
        if (node == NULL || node->val == val) return node;
        if (val < node->val) return search(node->left, val);
        return search(node->right, val);
    }

    TreeNode* deleteNode(TreeNode* node, int val) {
        if (node == NULL) return node;
        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val) != NULL;
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    void inorderTraversal(TreeNode* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            std::cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    void display() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};
