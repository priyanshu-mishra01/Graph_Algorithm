#include<bits/stdc++.h>
using namespace std;

// int numProvinces(vector<vector<int>> adj, int V) {
//         int cnt = 0;
//         vector<int>nums[V];
//         int vis[V]={0};
//         for(int i=0;i<V;i++) {
//             for(int j=0;j<V;j++) {
//                 if((i!=j) and adj[i][j]==1) {
//                     nums[i].push_back(j);
//                     nums[j].push_back(i);
//                 }
//             }
//         }
//         for (int i = 0; i < V; ++i)
//         {
//         	for(auto x)
//         }
//         for(int i=0;i<V;i++) {
//         queue<int>q;
//         if(!vis[i]) {
//             cnt++;
//             vis[i]=1;
//             q.push(i);
//         }    
//         while(!q.empty()) {
//             int node = q.front();
//             q.pop();
//             for(auto x : nums[node]) {
//                 if(!vis[x]) {
//                     vis[x]=1;
//                     q.push(x);
//                 }
//             }
//         }
//     }
// 	return cnt;
// }
void dfs(int node, vector<int>nums[], int vis[]) {
        vis[node]=1;
        for(auto x : nums[node])
        {
            if(!vis[x])
                dfs(x,nums,vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int cnt = 0;
        vector<int>nums[V];
        int vis[V]={0};
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                if((i!=j) and adj[i][j]==1) {
                    nums[i].push_back(j);
                    nums[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                    cnt++;
                    dfs(i,nums,vis);
                }
            }
            return cnt;
        }
int main()
{
	int V;
	cin>>V;
	vector<vector<int>> adj;
	for(int i=0;i<V;i++) {
		vector<int>v;
		for (int j = 0; j < V; ++j)
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		adj.push_back(v);
	}
	cout<<numProvinces(adj,V)<<endl;
}