#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;

void recursiveF(int source, int destination, unordered_set<int>& nodesWithAP, int airportsEstablished, vector<bool>& visited, bool& rFound) {
  // Aiports connected to source
  // for (int j = 0; j < graph[source].size(); j++) {
  //   //cout << graph[i][j] << " ";
  //   cout << "Airports connected to " << source ": ";
  //   if (graph[source][j] == 1) 
  //     cout << j + 1 << " ";
  // }

    for (int i = 0; i < graph[source].size(); i++) {
      if (graph[source][i] == destination) {
        if (nodesWithAP.count(destination) == 0) 
          airportsEstablished ++;
        rFound = true; 
        cout << "Route found\n";
        return;
      }

      // Output airport being checked checking for connections and if visited
      cout << "Checking Airport " << i + 1 << "\n";
      if (graph[source][i] == 1){
        cout << "Airport " << i + 1 << " has a connection\n";
      }
      cout << "Visited: " << visited[graph[source][i]] << "\n";

      // If airport is unvisited and has a connection then visit and check its connections
      if (graph[source][i] == 1 && visited[graph[source][i]] == false) {
        cout << "\nVisiting Airport " << graph[source][i] + 1 << "\n";

        cout << "Airport " << graph[source][i] + 1 << " marked as visited\n";
        visited[graph[source][i]] = true;
        recursiveF(graph[source][i], destination, nodesWithAP, airportsEstablished, visited, rFound);

        cout << "Return to Airport " << graph[source][i] << "\n";

        // If route is found add check if connection has an aiport and update airports established if not
        if(rFound == true && nodesWithAP.count(destination) == 0) {
          airportsEstablished++;
        }
        //return;
      }
    }
  cout << "\n";
  return;
}

int findRoute2(int source, int destination, vector<int>&citiesWithAP, int cities) {
  unordered_set<int> nodesWithAP(citiesWithAP.begin(), citiesWithAP.end());
  int airportsEstablished = 0; // keep track of airport routes established
  vector<bool> visited(cities, false); // keep track of airports visited
  bool rFound = false; // for if route is found

  visited[source - 1] = true; // mark source airport as visited

  // output contents of data
  cout << "Cities with Airports:\n";
      for (auto it = nodesWithAP.begin(); it != nodesWithAP.end(); ++it) {
          cout << *it << " ";
      }
      cout << "\n\nAvailable Routes:\n";
      for (int i = 0; i < graph.size(); i++) {
        cout << "Airport #" << i + 1 << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
          //cout << graph[i][j] << " ";
          if (graph[i][j] == 1) 
            cout << j + 1 << " ";
        }
        cout << "\n";
      }
      cout << "\n\n";

  //cout << "initial call s=" << source << " d=" << destination << "\n";
  
  recursiveF(source - 1, destination - 1, nodesWithAP, airportsEstablished, visited, rFound);

  if (rFound)
    return airportsEstablished;
  else
    return -1; // No route could be found
}

  
// run with ./main < data
int main() {
  int it, s, e, cities, routes, cityAirports, c = 0;

  cin >> it;

  while (it--) {
    cin >> cities >> routes >> cityAirports;
    vector<int> citiesWithAP;

    // read in all cities that have airports and save to vector
    for (int i = 0; i < cityAirports; i++) {
      cin >> s;
      citiesWithAP.push_back(s);
    }

    // reset all values in graph to -1
    graph.assign(cities, vector<int>(cities, -1));

    // save all routes to graph that are available, subtract one from each location to start at index 0
    for (int i = 0; i < routes; i++) {
      cin >> s >> e;
      graph[s - 1][e - 1] = graph[e - 1][s - 1] = 1;
    }

      // for (int i = 0; i < graph.size(); i++) {
      //   for (int j = 0; j < graph[i].size(); j++) 
      //     cout << graph[i][j] << " ";
      // }

    int requests;
    cin >> requests;

    // run requested connections through dijkstra's algorithm to determin how many routes need to be established to make a connection
    cout << "Case " << ++c << ":\n";
    for (int i = 0; i < requests; i++) {
      cin >> s >> e;
      cout << "Requested Airport " << s << " to " << e << "\n";
      int ap = findRoute2(s, e, citiesWithAP, cities);
      if (ap > -1) {
        cout << "Routes established " << ap << "\n";
      }
      else
        cout << "Impossible to establish route\n";
      cout << "\n====================\n\n";
    }    
  }
}

//int ap = dijkstra(s - 1, e - 1, citiesWithAP, cities);
// Returns the correct results for initial dataset (data) by coincidence but is wrong for other test inputs (data2)
// int dijkstra(int source, int destination, vector<int>& citiesWithAP, int cities) {
//     //int cities = graph.size();
//     vector<int> distance(cities, 1e9);
//     vector<bool> visited(cities, false);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     // set of all cities with airports
//     unordered_set<int> nodesWithAP(citiesWithAP.begin(), citiesWithAP.end()); 
//     int airportsEstablished = 0; // keep track of airport routes established

//     distance[source] = 0;
//     pq.push({0, source});
//     visited[source] = true;

//     // output values
//     cout << "Cities with Airports:\n";
//     for (auto it = nodesWithAP.begin(); it != nodesWithAP.end(); ++it) {
//         cout << *it << " ";
//     }
//     cout << "\n\nAvailable Routes:\n";
//     for (int i = 0; i < graph.size(); i++) {
//       cout << "Airport #" << i + 1 << ": ";
//       for (int j = 0; j < graph[i].size(); j++) {
//         //cout << graph[i][j] << " ";
//         if (graph[i][j] == 1) 
//           cout << j + 1 << " ";
//       }
//       cout << "\n";
//     }
//     cout << "\n\n";

//     // bool startAp = false;
//     // for (int i = 0; i < citiesWithAP.size(); i++) {
//     //   if (citiesWithAP[i] == source) 
//     //     startAp = true;
//     // }
//     // if (!startAp) 
//     //   airportsEstablished++;

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         int dist = pq.top().first;
//         pq.pop();

//       cout << "u: " << u << " dist: " << dist << "\n";

//         // if destination is found return how many routes were established
//         if (u == destination)
//             return airportsEstablished;

//         // if airport is unvisited, establish airport route unless there is already an airport present.
//         if (!visited[u]) {
//           visited[u] = true;
//           airportsEstablished += nodesWithAP.count(u) == 0;
//           if (nodesWithAP.count(u) == 0) {
//             cout << "Airport established at city " << u << "\n";
//           }
//         }

//         // check neighbors
//         for (int v = 0; v < cities; v++) {
//             if (graph[u][v] != -1 && !visited[v]) {
//                 int newDist = dist + graph[u][v];
//                 if (newDist < distance[v]) {
//                     distance[v] = newDist;
//                     pq.push({newDist, v});
//                 }
//             }
//         }
//     }

//     // return -1 if no route can be established
//     return -1;
// }