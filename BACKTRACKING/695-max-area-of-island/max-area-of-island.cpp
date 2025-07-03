class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        
        grid[i][j]=2;
        int area=1;
        
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            area+=dfs(grid,newi,newj);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};