//DSU is a data structure used to manage a partition of a set into disjoint subsets. It supports operations like union (merging two subsets) and find (finding the representative element of a subset). 

#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
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

int main() {
    int n; // Number of elements
    cin >> n;
    DSU dsu(n);

    // Example usage: unionSets and find operations
    dsu.unionSets(0, 1);
    dsu.unionSets(2, 3);
    dsu.unionSets(0, 3);

    cout << "Are 1 and 2 in the same set? " << (dsu.find(1) == dsu.find(2) ? "Yes" : "No") << endl;
    cout << "Are 0 and 3 in the same set? " << (dsu.find(0) == dsu.find(3) ? "Yes" : "No") << endl;

    return 0;
}
