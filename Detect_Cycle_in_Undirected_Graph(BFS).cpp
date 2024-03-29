#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // BFS Code
    bool bfs(int node, vector<int>adj[], vector<int>&vis) {
        // {node, parent}
        queue<pair<int,int>>q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()) {
            int ele = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto x : adj[ele]) {
                if(!vis[x]) {
                    q.push({x, ele});
                    vis[x]=1;
                }
                else if(x!=parent)
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(bfs(i, adj, vis)==true)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends