#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX

class BipGraph
{
	int m, n;

	list<int> *adj;

	int *pairU, *pairV, *dist;

public:
	BipGraph(int m, int n); 
	void addEdge(int u, int v); 

	bool bfs();

	bool dfs(int u);

	int hopcroftKarp();
};

int BipGraph::hopcroftKarp()
{
	pairU = new int[m+1];

	pairV = new int[n+1];

	dist = new int[m+1];

	for (int u=0; u<=m; u++)
		pairU[u] = NIL;
	for (int v=0; v<=n; v++)
		pairV[v] = NIL;

	int result = 0;

	while (bfs())
	{
		for (int u=1; u<=m; u++)

			if (pairU[u]==NIL && dfs(u))
				result++;
	}
	return result;
}

bool BipGraph::bfs()
{
	queue<int> Q; 

	for (int u=1; u<=m; u++)
	{
		if (pairU[u]==NIL)
		{
			dist[u] = 0;
			Q.push(u);
		}

		else dist[u] = INF;
	}

	dist[NIL] = INF;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		if (dist[u] < dist[NIL])
		{
			list<int>::iterator i;
			for (i=adj[u].begin(); i!=adj[u].end(); ++i)
			{
				int v = *i;

				if (dist[pairV[v]] == INF)
				{
					dist[pairV[v]] = dist[u] + 1;
					Q.push(pairV[v]);
				}
			}
		}
	}

	return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u)
{
	if (u != NIL)
	{
		list<int>::iterator i;
		for (i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			int v = *i;

			if (dist[pairV[v]] == dist[u]+1)
			{
				if (dfs(pairV[v]) == true)
				{
					pairV[v] = u;
					pairU[u] = v;
					return true;
				}
			}
		}

		dist[u] = INF;
		return false;
	}
	return true;
}

BipGraph::BipGraph(int m, int n)
{
	this->m = m;
	this->n = n;
	adj = new list<int>[m+1];
}

void BipGraph::addEdge(int u, int v)
{
	adj[u].push_back(v); 
}

int main()
{
	BipGraph g(4, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 1);
	g.addEdge(3, 2);
	g.addEdge(4, 2);
	g.addEdge(4, 4);

	cout << "Size of maximum matching is " << g.hopcroftKarp();

	return 0;
}
