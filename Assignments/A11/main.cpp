#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Edge {
  int to;
  int weight;
};

int prim(vector<vector<Edge>>& graph, int start) {
    int stations = graph.size();
    vector<bool> visited(stations, false); // Keep track of visited nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int minCost = 0; // Initialize the total cost of the MST
    int visitedCount = 0; // Keep track of the number of visited nodes

    // Push the start node into the priority queue with a distance of 0
    pq.push({0, start});

    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        int u = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();

        // If the current node has already been visited, skip it
        if (visited[u]) {
            continue;
        }

        // Mark the current node as visited
        visited[u] = true;
        visitedCount++;

        // Add the current edge's weight to the total cost of the MST
        minCost += currCost;

        // Explore neighbors of the current node
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If the neighbor hasn't been visited and the weight is smaller, add it to the priority queue
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    if (visitedCount != stations) {
      return -1;
    }

    return minCost;
}

int main() {
  int stations, connections, cost, weight;
  string start, end, firstStation;

  map<string, int> stationIndex;

  while (true) {
    cin >> stations >> connections;

    if (stations == 0 && connections == 0)
      break;

    vector<vector<Edge>> graph(stations);

    stationIndex.clear();

    for (int i = 0; i < stations; ++i) {
        string stationName;
        cin >> stationName;
        stationIndex[stationName] = i; // Map station names to their indices
    }

    for (int i = 0; i < connections; ++i) {
      cin >> start >> end >> weight;
      graph[stationIndex[start]].push_back({stationIndex[end], weight});
      graph[stationIndex[end]].push_back({stationIndex[start], weight});
    }

    cin >> firstStation;

    cost = prim(graph, stationIndex[firstStation]);

    if (cost != -1)
      cout << cost << "\n";
    else
      cout << "Impossible\n";
  }
}