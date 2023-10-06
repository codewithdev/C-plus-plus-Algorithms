#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> dist;

    Graph(int vertices) {
        V = vertices;
        dist.resize(V, vector<int>(V, INF));

        // Initialize diagonal elements to 0
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int w) {
        dist[u][v] = w;
    }

    void floydWarshall() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Shortest distances between all pairs of vertices:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << "\n";
        }
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

    g.floydWarshall();

    return 0;
}
