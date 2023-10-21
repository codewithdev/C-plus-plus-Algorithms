
//Prim's algorithm is another approach to find the Minimum Spanning Tree (MST). It starts with an arbitrary vertex and grows the MST one vertex at a time by selecting the edge with the minimum weight.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int primMST() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);

        int src = 0; // Start from vertex 0
        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (pair<int, int>& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        int minimumCost = 0;
        for (int i = 0; i < V; i++) {
            minimumCost += key[i];
        }

        return minimumCost;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int minimumCost = g.primMST();
    cout << "Minimum Cost of MST: " << minimumCost << endl;

    return 0;
}
