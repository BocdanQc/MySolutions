/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond with ChatGPT
//
// Description: C++ solutions to implement a graph class.
//              Dijkstra Search algorithm for the shortest path.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <climits>

class Graph {
private:
    std::map<int, std::list<std::pair<int, int>>> adjList; // node, <neighbor, weight>

public:
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // Ensure bidirectional edges
    }

    void dijkstra(int start) {
        // Step 1: Initialize distances
        std::map<int, int> dist;
        for (auto& node : adjList) {
            dist[node.first] = INT_MAX;
        }
        dist[start] = 0;

        // Step 2: Initialize set for processing nodes
        std::set<std::pair<int, int>> set; // <distance, node>
        set.insert({0, start});

        // Step 3: Process the graph
        while (!set.empty()) {
            // Extract the node with the smallest distance
            auto top = *(set.begin());
            int node = top.second;
            int nodeDist = top.first;
            set.erase(set.begin());

            // Update distances for all neighbors of the current node
            for (auto& neighbor : adjList[node]) {
                int newDist = nodeDist + neighbor.second;
                if (newDist < dist[neighbor.first]) {
                    // If the neighbor is already in the set, remove it
                    auto f = set.find({dist[neighbor.first], neighbor.first});
                    if (f != set.end()) {
                        set.erase(f);
                    }
                    // Update the distance and insert the neighbor with the new distance
                    dist[neighbor.first] = newDist;
                    set.insert({newDist, neighbor.first});
                }
            }
        }

        // Step 4: Print the shortest distances
        for (auto& d : dist) {
            std::cout << "Node: " << d.first << " Distance: " << d.second << std::endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    g.dijkstra(0); // Find shortest paths from node 0

    return 0;
}
