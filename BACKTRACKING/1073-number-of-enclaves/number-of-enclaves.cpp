class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void dfs(vector<vector<int>>& board,int i,int j){
        int r = board.size();
        int c = board[0].size();
        board[i][j]=2;
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            if(newi<=0||newj<=0||newi>=r-1||newj>=c-1){
                continue;
            }
            if(board[newi][newj]==1){
                dfs(board,newi,newj);
            }
        }
    }


    int numEnclaves(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(i==0||j==0||i==r-1||j==c-1){
                    if(board[i][j]==1) 
                        dfs(board,i,j);
                }
            }
        }
        int ans=0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(board[i][j]==2){
                    board[i][j]=1;
                } else if(board[i][j]==1) ans++;
            }
        }
        return ans;
    }
};