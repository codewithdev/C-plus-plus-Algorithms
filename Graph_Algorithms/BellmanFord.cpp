#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E; // Number of vertices and edges
    vector<Edge> edges;

    Graph(int vertices, int edgesCount) {
        V = vertices;
        E = edgesCount;
        edges.resize(E);
    }

    void addEdge(int u, int v, int w, int edgeIndex) {
        edges[edgeIndex].src = u;
        edges[edgeIndex].dest = v;
        edges[edgeIndex].weight = w;
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Negative-weight cycle detected!" << endl;
                return;
            }
        }

        cout << "Shortest distances from vertex " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E;
    Graph g(V, E);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w, i);
    }

    int src; // Source vertex for Bellman-Ford
    cin >> src;

    g.bellmanFord(src);

    return 0;
}
