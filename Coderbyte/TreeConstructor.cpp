/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Tree Constructor problem from Coderbyte:
//              https://coderbyte.com/information/Tree%20Constructor
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <climits>

using namespace std;

struct Node {
  static const int NONE = INT_MIN;
  
  int parent;
  int childLeft;
  int childRight;
  
  Node() : parent(NONE), childLeft(NONE), childRight(NONE) { }
  Node(int p, int c1, int c2) : parent(p), childLeft(c1), childRight(c2) { }

  bool AddParent(int p) {
    bool isOk = true;
    if (parent == NONE)
      parent = p;
    else
      isOk = false;
    return isOk;
  }
  bool AddChild(int c) {
    bool isOk = true;
    if (childLeft == NONE)
      childLeft = c;
    else if (childRight == NONE)
      childRight = c;
    else
      isOk = false;
    return isOk;
  }

  bool IsRoot()  { return parent == NONE; }
  bool IsLeaf()  { return childLeft == NONE && childRight == NONE; }
  bool IsEmpty() { return IsRoot() && IsLeaf(); }
};

pair<int, int> ExtractCoupleValues(string str) {
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] == '(' || str[i] == ')')
      str.erase(str.begin() + i);
  }
  int first  = stoi(str.substr(0, str.find(',')));
  int second = stoi(str.substr(str.find(',') + 1));
  return make_pair(first, second);
}

string TreeConstructor(string strArr[], int arrLength) {
  map<int, Node> binaryTree;
  // Contrust the Binary Tree
  for (int i = 0; i < arrLength; i++) {
    // Extract the couple values from the string
    pair<int, int> couple = ExtractCoupleValues(strArr[i]);
    // Cannot add a couple where the child is also the parent
    if (couple.first == couple.second)
      return string("false");
    // Verify if the child is already part of the tree, if not add it as a leaf
    if (binaryTree.find(couple.first) == binaryTree.end()) {
      Node n(couple.second, Node::NONE, Node::NONE);
      binaryTree[couple.first] = n;
    }
    // Add its parent if it is a root, if not it is an invalid tree (cannot have 2 parents)
    else if (!binaryTree[couple.first].AddParent(couple.second))
      return string("false");

    // Verify if the parent is already part of the tree, if not add it as a root
    if (binaryTree.find(couple.second) == binaryTree.end()) {
      Node n(Node::NONE, couple.first, Node::NONE);
      binaryTree[couple.second] = n;
    }
    // Add its child if it is has no more than 1 child alread (cannot have 3 children),
    // if it is a third child mark the three as invalid
    else if (!binaryTree[couple.second].AddChild(couple.first))
      return string("false");
  }

  // Loop through the nodes to see if there are multiple roots (i.e.: orphan nodes)
  // Having multiple roots is invalid (multiple binary trees instead of 1)
  int nbRoots = 0;
  for (auto it = binaryTree.begin(); it != binaryTree.end(); ++it) {
    if (it->second.IsRoot())
      nbRoots++;
    if (nbRoots > 1)
      return string("false");
  }
  
  // If there is no root, it means a circular reference and it is not a binary tree
  if (nbRoots == 0)
    return string("false");
  
  return string("true");

}

int main(void) { 
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << TreeConstructor(A, arrLength);
  return 0;
}