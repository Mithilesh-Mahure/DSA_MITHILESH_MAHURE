class Solution {
public:
    int r, c;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    void dfs(vector<vector<int>>& image, int i, int j, int color,
             int orignal_color, vector<vector<int>>& visited) {
        if (i < 0 || j < 0 || i >= r || j >= c || orignal_color != image[i][j] || visited[i][j]) return; 
        image[i][j] =color;
        visited[i][j]=1;

        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            if (newi >= 0 && newj >= 0 && newi < r && newj < c && !visited[newi][newj]){
                dfs(image,newi,newj,color,orignal_color,visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        r = image.size();
        c = image[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        int orignal_color = image[sr][sc];

        if (orignal_color == color)
            return image;

        dfs(image, sr, sc, color, orignal_color, visited);

        return image;
    }
};