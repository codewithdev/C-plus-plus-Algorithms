// Distance from the Source (Bellman-Ford Algorithm) 

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
            // TC-> O(V-1) * O(E) | SC-> O(V)
          vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
                vector<int> dist(V, 1e8);
                dist[S] = 0;
                for(int i = 1; i <= V-1; i++)
                {
                    for(auto it: edges){
                        int u = it[0];
                        int v = it[1];
                        int wt = it[2];
                        
                        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                            dist[v] = dist[u] + wt;
                    }
                }
                
                // do the last relaxation for Vth time 
                // to check if negative edge cycle exists
                for(auto it: edges){
                        int u = it[0];
                        int v = it[1];
                        int wt = it[2];
                        
                        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                        return {-1};
                }
                return dist;
        }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
