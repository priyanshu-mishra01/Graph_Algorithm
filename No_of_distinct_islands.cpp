class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v,int row0, int col0){
        int n = grid.size(), m = grid[0].size();
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = row + dr[i], nc = col + dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and !vis[nr][nc]){
                dfs(nr,nc,vis,grid,v,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m ;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,grid,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};