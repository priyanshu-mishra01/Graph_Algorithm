// DFS TC - O(N*M*4) SC-O(N*M)
class Solution1 {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int j=0;j<m;j++){
            if(!vis[0][j] and grid[0][j]==1)
                dfs(0,j,grid,vis,dr,dc);
            if(!vis[n-1][j] and grid[n-1][j]==1)
                dfs(n-1,j,grid,vis,dr,dc);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] and grid[i][0]==1)
                dfs(i,0,grid,vis,dr,dc);
            if(!vis[i][m-1] and grid[i][m-1]==1)
                dfs(i,m-1,grid,vis,dr,dc);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
private:
    void dfs(int r, int c, vector<vector<int>>&grid,vector<vector<int>>&vis,int dr[],int dc[]){
        int n = grid.size(), m = grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,dr,dc);
            }
        }
    }
};
// BFS TC- O(N*M) + O(N*M*4) SC-O(N*M)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==(n-1) or j==(m-1)){
                    if(!vis[i][j] and grid[i][j]==1)
                        q.push({i,j});
                        vis[i][j]=1;
                }
            }
        }
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};