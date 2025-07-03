class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void dfs(vector<vector<char>>& board,int i,int j){
        int r = board.size();
        int c = board[0].size();
        board[i][j]='T';
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            if(newi<=0||newj<=0||newi>=r-1||newj>=c-1){
                continue;
            }
            if(board[newi][newj]=='O'){
                dfs(board,newi,newj);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(i==0||j==0||i==r-1||j==c-1){
                    if(board[i][j]=='O') 
                        dfs(board,i,j);
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }else {
                    board[i][j]='X';
                }
            }
        }
    }
};