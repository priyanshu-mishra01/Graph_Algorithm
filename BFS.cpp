#include<bits/stdc++.h>
using namespace std;

//BFS 
// TC-> O(v) + O(2E)
// SC-> O(3V)
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>bfs;
        int vis[V] = {0};
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto x : adj[node]) {
                if(!vis[x]) {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return bfs;
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
	vector<int>res = bfsOfGraph(n,adj);
	for(auto x : res)
		cout<<x<<" ";
	cout<<endl;
}