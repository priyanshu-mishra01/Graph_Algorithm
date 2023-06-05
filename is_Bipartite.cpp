class Solution1 {
public:
    bool dfs(int node, int col, vector<int>&color,vector<vector<int>>& graph){
        color[node]=col;
        for(auto x : graph[node]) {
            if(color[x]==-1){
                if(dfs(x,!col,color,graph)==false)
                    return false;
                // this node is previously colored and have the same color
            }
                else if(color[x]==col)
                    return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false)
                    return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool bfs(int node, vector<int>&color, vector<vector<int>>&graph){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto x : graph[ele]){
                if(color[x]==-1){
                    q.push(x);
                    color[x]=!color[ele];
                }
                else if(color[x]==color[ele])
                    return false;
            }
        }
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0; i<n; i++) {
            if(color[i]==-1) {
                if(bfs(i,color,graph)==false)
                    return false;
            }
        }
        return true;
    }
};