#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// struct for holding each path
struct Edge {
    int source, destination, weight;
};

// Adds paths using the above struct
void addEdge(vector<vector<Edge>> &paths, int source, int destination, int weight) {
    Edge path = {source, destination, weight};
    paths[source].push_back(path);
}

// Dijkstra's method being used to find the shortest path to a given destination
int dijkstra(vector<vector<Edge>> &graph, int source, int destination) {
    int V = graph.size();
    priority_queue<pair<int, int>> pq;
    vector<int> capacities(V, 0);
    pq.push({1e9, source});
    capacities[source] = 1e9;

    while (!pq.empty()) {
        int u = pq.top().second;
        int capacity = pq.top().first;
        pq.pop();

        if (u == destination) {
            return capacity;
        }

        for (const auto &neighbor : graph[u]) {
            int v = neighbor.destination;
            int edge_capacity = neighbor.weight;
            int min_capacity = min(capacity, edge_capacity);
            if (min_capacity > capacities[v]) {
                capacities[v] = min_capacity;
                pq.push({min_capacity, v});
            }
        }
    } 

    return 0;
}

int main() {
    int cities, roads, start, end, weight, pass, min, trips, it = 0;  

    while (true) {
        cin >> cities >> roads;

        // if end of file reached
        if (cities == 0 && roads == 0)
          break;

        // create vector for cities
        vector<vector<Edge>> paths(cities + 1);

        // read in all edges
        for (int i = 0; i < roads; i++) {
            cin >> start >> end >> weight;
            addEdge(paths, start, end, weight);
            addEdge(paths, end, start, weight);
        }

        cin >> start >> end >> pass;

        // Using dijkstra's method find the shortest path and determine how many trips it will take
        min = dijkstra(paths, start, end);
        trips = (pass + min - 2) / (min - 1);

        cout << "Scenario #" << ++it << "\nMinimum Number of Trips = " << trips << "\n\n";
    }
    
    return 0;
}  