class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0; i<m; i++) {
            // first row
            if(board[0][i]=='O' and !vis[0][i])
                dfs(0,i,board,vis);
            // last row
            if(board[n-1][i]=='O' and !vis[n-1][i])
                dfs(n-1,i,board,vis);
        }
        for(int i=0; i<n; i++) {
            // first col
            if(board[i][0]=='O' and !vis[i][0])
                dfs(i,0,board,vis);
            // last col
            if(board[i][m-1]=='O' and !vis[i][m-1])
                dfs(i,m-1,board,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
private:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int r, int c, vector<vector<char>>board, vector<vector<int>>&vis){
        vis[r][c]=1;
        int n = board.size(),m = board[0].size();
        for(int i=0;i<4;i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]=='O' and !vis[nr][nc]){
                dfs(nr,nc,board,vis);
            }
        }
    }
};