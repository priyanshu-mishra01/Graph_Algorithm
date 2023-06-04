class Solution {
public:
    void solve(int sr, int sc, vector<vector<int>>&image, int& oldColor, int color) {
        int n = image.size(),m=image[0].size();
        image[sr][sc]=color;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        for(int i=0; i<4; i++) {
            int nr = sr + dr[i], nc = sc + dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==oldColor){
                solve(nr,nc,image,oldColor,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int oldcolor = image[sr][sc];
        solve(sr,sc,image,oldcolor,color);
        return image;
    }
};