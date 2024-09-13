/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond with ChatGPT
//
// Description: C++ solution to implement a Red-Black Balanced Binary Tree class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    Node* root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixInsert(Node *&);
    void fixDelete(Node *&, Node *&);
    void inorderHelper(Node *) const;
    void printTreeHelper(Node *, int) const;
    Node* successor(Node *);
    Node* predecessor(Node *);
    void transplant(Node *, Node *);
    Node* minValueNode(Node *);
    Node* maxValueNode(Node *);

public:
    RedBlackTree();
    void insert(const int &);
    void deleteNode(const int &);
    void inorder() const;
    void printTree() const;
};

RedBlackTree::RedBlackTree() { root = nullptr; }

void RedBlackTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::fixInsert(Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node *uncle_pt = grand_parent_pt->left;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::insert(const int &data) {
    Node *pt = new Node(data);

    if (root == nullptr) {
        pt->color = BLACK;
        root = pt;
    } else {
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (pt->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;

        if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        fixInsert(pt);
    }
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
}

void RedBlackTree::fixDelete(Node *&root, Node *&x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;

            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(root, x->parent);
                w = x->parent->right;
            }

            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == BLACK) {
                    if (w->left != nullptr)
                        w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(root, w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != nullptr)
                    w->right->color = BLACK;
                rotateLeft(root, x->parent);
                x = root;
            }
        } else {
            Node *w = x->parent->left;

            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(root, x->parent);
                w = x->parent->left;
            }

            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == BLACK) {
                    if (w->right != nullptr)
                        w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(root, w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != nullptr)
                    w->left->color = BLACK;
                rotateRight(root, x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::deleteNode(const int &data) {
    Node *v = root;
    Node *u = nullptr, *x = nullptr;
    while (v != nullptr) {
        if (v->data == data)
            break;
        if (v->data < data)
            v = v->right;
        else
            v = v->left;
    }

    if (v == nullptr) {
        cout << "No node found to delete with data " << data << endl;
        return;
    }

    u = v;
    bool uOriginalColor = u->color;

    if (v->left == nullptr) {
        x = v->right;
        transplant(v, v->right);
    } else if (v->right == nullptr) {
        x = v->left;
        transplant(v, v->left);
    } else {
        u = minValueNode(v->right);
        uOriginalColor = u->color;
        x = u->right;
        if (u->parent == v) {
            if (x != nullptr)
                x->parent = u;
        } else {
            transplant(u, u->right);
            u->right = v->right;
            if (u->right != nullptr)
                u->right->parent = u;
        }
        transplant(v, u);
        u->left = v->left;
        u->left->parent = u;
        u->color = v->color;
    }

    delete v;
    if (uOriginalColor == BLACK && x != nullptr)
        fixDelete(root, x);
}

void RedBlackTree::inorderHelper(Node *root) const {
    if (root == nullptr)
        return;

    inorderHelper(root->left);
    cout << root->data << (root->color == RED ? "R " : "B ");
    inorderHelper(root->right);
}

void RedBlackTree::inorder() const {
    inorderHelper(root);
}

void RedBlackTree::printTreeHelper(Node *root, int space) const {
    if (root == nullptr)
        return;

    space += 10;

    printTreeHelper(root->right, space);

    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->data << (root->color == RED ? "R" : "B") << "\n";

    printTreeHelper(root->left, space);
}

void RedBlackTree::printTree() const {
    printTreeHelper(root, 0);
}

Node* RedBlackTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* RedBlackTree::maxValueNode(Node* node) {
    Node* current = node;
    while (current->right != nullptr)
        current = current->right;
    return current;
}

Node* RedBlackTree::successor(Node* node) {
    if (node->right != nullptr)
        return minValueNode(node->right);
    Node* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* RedBlackTree::predecessor(Node* node) {
    if (node->left != nullptr)
        return maxValueNode(node->left);
    Node* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

int main() {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);

    cout << "Inorder Traversal of Created Tree: ";
    tree.inorder();
    cout << endl;

    cout << "Print Tree: ";
    tree.printTree();
    cout << endl;

    cout << "Delete 5\n";
    tree.deleteNode(5);
    cout << "Inorder Traversal after Deletion of 5: ";
    tree.inorder();
    cout << endl;

    cout << "Print Tree: ";
    tree.printTree();
    cout << endl;

    return 0;
}
