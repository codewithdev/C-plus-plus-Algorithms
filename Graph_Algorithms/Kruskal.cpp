
//Kruskal's algorithm is used to find the Minimum Spanning Tree (MST) of a connected, undirected graph. It does this by selecting edges with the smallest weight while avoiding cycles.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<Edge> kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Edge> minimumSpanningTree;
    UnionFind uf(n);

    for (Edge edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            minimumSpanningTree.push_back(edge);
            uf.unionSets(edge.u, edge.v);
        }
    }

    return minimumSpanningTree;
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    vector<Edge> minimumSpanningTree = kruskalMST(edges, n);

    cout << "Minimum Spanning Tree Edges:\n";
    for (Edge edge : minimumSpanningTree) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    return 0;
}
