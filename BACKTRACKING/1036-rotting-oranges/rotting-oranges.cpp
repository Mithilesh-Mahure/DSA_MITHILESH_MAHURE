class Solution {
public:
    int r, c;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int res = 0;
        queue<pair<int, int>> qp;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    qp.push({i, j});
                }
            }
        }
        while (!qp.empty()) {
            int sz = qp.size();
            int flag = 0;
            while (sz--) {
                auto x = qp.front();qp.pop();
                for (int k = 0; k < 4; k++) {
                    int i = x.first +dx[k], j = x.second+dy[k];
                    if (i >= 0 && j >= 0 && i < r && j < c && grid[i][j] == 1){
                        grid[i][j] =2;
                        flag=1;
                        qp.push({i,j});
                    }
                }
            }
            res += flag;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};