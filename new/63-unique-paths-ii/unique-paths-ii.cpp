class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size(); // columns
        int m = obstacleGrid.size();    // rows
        int t[m + 1][n + 1];
        memset(t, 0, sizeof(t));
        t[1][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if(obstacleGrid[i-1][j-1]==0){
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[m][n];
    }
};

/*


class Solution {
public:
    struct Choice {
        char dname;
        int dx, dy;
    };
    bool isSolved(int x, int y, int m, int n) { return ((x == m-1) && (y ==
n-1)); } bool isValid(int x, int y, int m, int n, vector<vector<int>>&
obstacleGrid) { return ((x >= 0 && x < m) && (y >= 0 && y < n) &&
                (obstacleGrid[x][y] == 0));
    }

    void solve(int x, int y, int m, int n, vector<string>& res, string& path,
               vector<vector<int>>& obstacleGrid,
               const vector<Choice>& choices) {
        if (isSolved(x, y, m, n)) {
            res.push_back(path);
            return;
        }

        for (const auto& choice : choices) {
            int newX = x + choice.dx;
            int newY = y + choice.dy;
            if (isValid(newX, newY, m, n, obstacleGrid)) {
                obstacleGrid[newX][newY] =1;
                path.push_back(choice.dname);
                solve(newX, newY, m, n, res, path, obstacleGrid, choices);
                obstacleGrid[newX][newY] =0;
                path.pop_back();
            }
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();//columns
        int m = obstacleGrid.size();//rows
        vector<string> res;
        string path;

        vector<Choice> choices = {{'D', 1, 0}, {'R', 0, 1}};
        if (obstacleGrid[0][0] == 0 && obstacleGrid[m - 1][n - 1] == 0) {
            solve(0, 0, m, n, res, path, obstacleGrid, choices);
        }
        return res.size();
    }
};

*/