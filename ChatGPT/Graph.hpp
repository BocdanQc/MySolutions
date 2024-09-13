/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond with ChatGPT
//
// Description: Different C++ solutions to implement a graph class.
//              Breadth First Search vs Depth First Search
//              unordered_map vs unordered_set
//              recursion vs iteration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;

public:
    void AddEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    void BreadthFirstSearch(int start) {
        std::unordered_map<int, bool> visited;
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int vertex = queue.front();
            std::cout << vertex << " ";
            queue.pop();

            for (auto adj : adjList[vertex]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue.push(adj);
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int v, std::unordered_map<int, bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto adj : adjList[v]) {
            if (!visited[adj]) {
                DFS(adj, visited);
            }
        }
    }

    void DepthFirstSearch(int start) {
        std::unordered_map<int, bool> visited;
        DFS(start, visited);
        std::cout << std::endl;
    }
};


int main() {
    Graph g;
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(1, 4);

    std::cout << "Breadth-First Search starting from node 0: ";
    g.BreadthFirstSearch(0);

    std::cout << "Depth-First Search starting from node 0: ";
    g.DepthFirstSearch(0);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>

class Graph {
private:
    int nbVertices; // Number of vertices
    std::unordered_set<int> *adjList; // Adjacency list

public:
    Graph(int v) {
        nbVertices = v;
        adjList = new std::unordered_set<int>[v];
    }

    void addEdge(int v, int w) {
        adjList[v].insert(w);
        adjList[w].insert(v); // Add this line for undirected graph
    }

    void BreadthFirstSearch(int start) {
        std::vector<bool> visited(nbVertices, false);
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int v = queue.front();
            std::cout << v << " ";
            queue.pop();

            for (int w : adjList[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    queue.push(w);
                }
            }
        }
        std::cout << std::endl;
    }

    void DepthFirstSearch(int start) {
        std::vector<bool> visited(nbVertices, false);
        std::stack<int> stack;

        stack.push(start);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                std::cout << v << " ";
                visited[v] = true;
            }

            for (int w : adjList[v]) {
                if (!visited[w]) {
                    stack.push(w);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    std::cout << "Breadth-First Search starting from node 0: ";
    g.BreadthFirstSearch(0);

    std::cout << "Depth-First Search starting from node 0: ";
    g.DepthFirstSearch(0);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

class Graph {
private:
    std::unordered_map<int, std::unordered_set<int>> adjList; // Adjacency list

public:
    void AddEdge(int v, int w) {
        adjList[v].insert(w);
        adjList[w].insert(v); // Ensure bidirectional edges
    }

    void BreadthFirstSearch(int start) {
        std::unordered_map<int, bool> visited;
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int v = queue.front();
            std::cout << v << " ";
            queue.pop();

            for (int w : adjList[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    queue.push(w);
                }
            }
        }
        std::cout << std::endl;
    }

    void DepthFirstSearch(int start) {
        std::unordered_map<int, bool> visited;
        std::stack<int> stack;

        stack.push(start);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                std::cout << v << " ";
                visited[v] = true;
            }

            for (int w : adjList[v]) {
                if (!visited[w]) {
                    stack.push(w);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g;
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);

    std::cout << "Breadth-First Search starting from node 3: ";
    g.BreadthFirstSearch(3);

    std::cout << "Depth-First Search starting from node 3: ";
    g.DepthFirstSearch(3);

    return 0;
}
