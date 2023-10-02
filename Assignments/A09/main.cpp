#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure to represent a graph (adjacency list)
struct Graph {
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V) {
        adjList.resize(vertices);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // BFS traversal starting from a given vertex
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " "; // Process the current vertex

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Perform BFS traversal from all unvisited vertices
    void performBFS() {
        vector<bool> visited(vertices, false);

        // Start BFS from each unvisited vertex
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                cout << "Starting BFS from vertex " << i << ": ";
                BFS(i);
                cout << endl;
            }
        }
    }
};

int main() {
    int x, y, z;

    while(cin >> z) {
        Graph g(z);

        // for(int i = 0; i < z; i++) {
        //     for (int j = 0; j < z; j++) {
        //         cin >> x >> y;
        //         g.addEdge(x, y);
        //     }
        // }

        g.addEdge(10, 9);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(1, 5);
        g.addEdge(1, 6);
        g.addEdge(1, 7);
        g.addEdge(1, 8);
        g.addEdge(1, 9);
        g.addEdge(1, 10);
        g.addEdge(10, 4);
        g.addEdge(2, 3);
        g.addEdge(4, 5);
        g.addEdge(4, 8);
        g.addEdge(5, 8);
        //g.addEdge(0, 0);


        g.BFS(0);

    }
}