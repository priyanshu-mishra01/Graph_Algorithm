#include<iostream>
using namespace std;

int main()
{
	// Adjacency matrix for undirected graph
	// TC->O(N^2) SC->O(N^2)
	int n, m;
	cin>>n>>m;
	int mat[n+1][m+1];
	memset(mat,0,sizeof(mat));
	for(int i=0;i<m;i++) {
		int u, v;
		cin>>u>>v;
		mat[u][v]=1; // if graph is weighted- mat[u][v]=w;
		mat[v][u]=1;
	}
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	//Adjacency List for undirected graph
	// TC->O(V+E) SC-> O(2E) it become O(E) in case of directed graph
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
	for(int i=0;i<n+1;i++){
		cout<<i<<": ";
		for(auto x : adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

//Weight graph using adjacency list------->
	int n , m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for (int i = 0; i < m; ++i)
	{
		int u, v,wt;
		cin>>u>>v;
		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(v,wt));
	}
}
