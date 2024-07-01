#include <iostream>
#include <algorithm> // for max function

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent; // Pointer to parent node
    int height;

    Node(int k, Node* p = nullptr) : key(k), left(nullptr), right(nullptr), parent(p), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insertIterative(Node* node, int key);
    Node* minValueNode(Node* node);
    Node* maxValueNode(Node* node);
    Node* deleteNodeIterative(Node* node, int key);
    void inorderTraversalHelper(Node* node, int depth);
    void printIndented(Node* node, int indent);

public:
    AVLTree();
    Node* getRoot();
    void insert(int key);
    void deleteKey(int key);
    Node* successor(Node* node);
    Node* predecessor(Node* node);
    void inorderTraversal();
    void printTree();
};

AVLTree::AVLTree() : root(nullptr) {}

Node* AVLTree::getRoot() { return root; }

int AVLTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update parent pointers
    if (T2 != nullptr)
        T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update parent pointers
    if (T2 != nullptr)
        T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::insertIterative(Node* node, int key) {
    // Perform standard BST insertion
    Node* parent = nullptr;
    Node* current = node;

    while (current != nullptr) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return node; // Duplicate keys not allowed in AVL trees
    }

    // Create new node
    Node* newNode = new Node(key, parent);

    // Insert the new node
    if (parent == nullptr)
        return newNode; // Tree is empty
    else if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Update heights and balance
    while (parent != nullptr) {
        parent->height = 1 + std::max(height(parent->left), height(parent->right));

        int balance = getBalance(parent);

        // Left Left Case
        if (balance > 1 && key < parent->left->key)
            parent = rotateRight(parent);

        // Right Right Case
        else if (balance < -1 && key > parent->right->key)
            parent = rotateLeft(parent);

        // Left Right Case
        else if (balance > 1 && key > parent->left->key) {
            parent->left = rotateLeft(parent->left);
            parent = rotateRight(parent);
        }

        // Right Left Case
        else if (balance < -1 && key < parent->right->key) {
            parent->right = rotateRight(parent->right);
            parent = rotateLeft(parent);
        }

        if (parent->parent != nullptr)
            parent = parent->parent;
        else
            break;
    }

    return parent;
}

void AVLTree::insert(int key) {
    root = insertIterative(root, key);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVLTree::maxValueNode(Node* node) {
    Node* current = node;
    while (current->right != nullptr)
        current = current->right;
    return current;
}

Node* AVLTree::deleteNodeIterative(Node* node, int key) {
    // Perform standard BST delete
    Node* current = node;
    Node* parent = nullptr;

    while (current != nullptr && current->key != key) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
        return node; // Key not found

    Node* child = (current->left == nullptr) ? current->right : current->left;

    if (child == nullptr) {
        // No child or one child case
        if (parent == nullptr)
            node = nullptr;
        else if (current == parent->left)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete current;
    } else {
        // Two children case
        Node* successor = minValueNode(current->right);
        int successorKey = successor->key;
        node = deleteNodeIterative(node, successorKey);
        current->key = successorKey;
    }

    // Update heights and balance
    while (parent != nullptr) {
        parent->height = 1 + std::max(height(parent->left), height(parent->right));

        int balance = getBalance(parent);

        // Left Left Case
        if (balance > 1 && getBalance(parent->left) >= 0)
            parent = rotateRight(parent);

        // Left Right Case
        if (balance > 1 && getBalance(parent->left) < 0) {
            parent->left = rotateLeft(parent->left);
            parent = rotateRight(parent);
        }

        // Right Right Case
        if (balance < -1 && getBalance(parent->right) <= 0)
            parent = rotateLeft(parent);

        // Right Left Case
        if (balance < -1 && getBalance(parent->right) > 0) {
            parent->right = rotateRight(parent->right);
            parent = rotateLeft(parent);
        }

        if (parent->parent != nullptr)
            parent = parent->parent;
        else
            break;
    }

    return parent;
}

void AVLTree::deleteKey(int key) {
    root = deleteNodeIterative(root, key);
}

Node* AVLTree::successor(Node* node) {
    if (node->right != nullptr)
        return minValueNode(node->right);

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* AVLTree::predecessor(Node* node) {
    if (node->left != nullptr)
        return maxValueNode(node->left);

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void AVLTree::inorderTraversalHelper(Node* node, int depth) {
    if (node != nullptr) {
        inorderTraversalHelper(node->left, depth + 1);
        std::cout << std::string(depth * 3, ' ') << node->key << std::endl;
        inorderTraversalHelper(node->right, depth + 1);
    }
}

void AVLTree::printIndented(Node* node, int indent) {
    if (node == nullptr)
        return;

    printIndented(node->right, indent + 5);
    std::cout << std::string(indent, ' ') << node->key << std::endl;
    printIndented(node->left, indent + 5);
}

void AVLTree::inorderTraversal() {
    inorderTraversalHelper(root, 0);
}

void AVLTree::printTree() {
    printIndented(root, 0);
}

int main() {
    AVLTree avl;

    // Insert some nodes
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);

    // Print tree structure
    std::cout << "AVL Tree Structure:" << std::endl;
    avl.printTree();

    // Delete a node
    avl.deleteKey(10);

    // Print tree structure after deletion
    std::cout << "\nAVL Tree Structure after deleting 10:" << std::endl;
    avl.printTree();

    // Example of using successor and predecessor
    Node* node = avl.getRoot()->left->right; // Node with key 6
    Node* successor = avl.successor(node);
    Node* predecessor = avl.predecessor(node);
    std::cout << "\nSuccessor of " << node->key << ": " << ((successor != nullptr) ? std::to_string(successor->key) : "nullptr") << std::endl;
    std::cout << "Predecessor of " << node->key << ": " << ((predecessor != nullptr) ? std::to_string(predecessor->key) : "nullptr") << std::endl;

    return 0;
}
