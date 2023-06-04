//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // DFS function
    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis) {
        int n = grid.size(), m = grid[0].size();
        vis[r][c]=1;
        // 8 directions
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++){
                int nr = r + i, nc = c + j;
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]=='1' and !vis[nr][nc]){
                    dfs(nr, nc, grid, vis);
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends