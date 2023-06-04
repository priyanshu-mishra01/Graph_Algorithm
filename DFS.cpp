#include<bits/stdc++.h>
using namespace std;

//DFS
// TC-> O(N+2E) SC->O(3V) for undirected graph;
// for directed graph is depned on no of Edges.
void solve(int node, int V, vector<int> adj[], vector<int>&res, int *vis) {
        res.push_back(node);
        vis[node]=1;
        for(auto x : adj[node]) {
            if(!vis[x]) {
                solve(x, V, adj, res, vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>res;
        int vis[V]={0};
        solve(0, V, adj, res, vis);
        return res;
    }
int main()
{
	int n , m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>res = dfsOfGraph(n,adj);
	for(auto x : res)
		cout<<x<<" ";
	cout<<endl;
}