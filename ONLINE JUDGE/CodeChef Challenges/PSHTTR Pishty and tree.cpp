// Solution for problem Pishty and Tree (PSHTTR) using Persistent Segment Tree
// Author: @nikolatechie

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *c[2];

    Node(int v = 0, Node *l = nullptr, Node *r = nullptr)
    {
        val = v;
        c[0] = l;
        c[1] = r;
    }
};

const int N = 1e5 + 5;
const int VAL = 1e9 + 5;
Node *root[N];
int n;
vector <pair <int,int>> g[N];

void Update(Node *oldRoot, Node *&newRoot, int sl, int sr, int pos)
{
    newRoot = new Node();

    if (sl == sr)
    {
        newRoot->val ^= sl;
        if (oldRoot != nullptr) newRoot->val ^= oldRoot->val;
        return;
    }

    int mid = (sl+sr)>>1;
    Node *L = nullptr, *R = nullptr;
    if (oldRoot != nullptr) L = oldRoot->c[0], R = oldRoot->c[1];

    if (pos <= mid)
    {
        newRoot->c[1] = R;
        Update(L, newRoot->c[0], sl, mid, pos);
    }
    else
    {
        newRoot->c[0] = L;
        Update(R, newRoot->c[1], mid+1, sr, pos);
    }

    L = newRoot->c[0], R = newRoot->c[1];
    if (L != nullptr) newRoot->val ^= L->val;
    if (R != nullptr) newRoot->val ^= R->val;
}

int Query(Node *&x, int sl, int sr, ci &l, ci &r)
{
    if (x == nullptr || l > r || sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return x->val;

    int mid = (sl+sr)>>1;

    return Query(x->c[0], sl, mid, l, r) ^
        Query(x->c[1], mid+1, sr, l, r);
}

void DFS(int node, int p)
{
    for (const auto &it: g[node])
    {
        int ngb = it.first, cost = it.second;
        if (ngb == node || ngb == p) continue;
        Update(root[node], root[ngb], 1, VAL, cost);
        DFS(ngb, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int TC;
    cin >> TC;

    while (TC)
    {
        --TC;
        cin >> n;

        for (int t1 = 1; t1 <= n; ++t1)
        {
            g[t1].clear();
            root[t1] = nullptr;
        }

        for (int t1 = 1; t1 < n; ++t1)
        {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        DFS(1, -1);
        int q;
        cin >> q;

        while (q)
        {
            --q;
            int a, b, k;
            cin >> a >> b >> k;
            cout << (Query(root[a], 1, VAL, 1, k) ^
                    Query(root[b], 1, VAL, 1, k)) << '\n';
        }
    }

    return 0;
}