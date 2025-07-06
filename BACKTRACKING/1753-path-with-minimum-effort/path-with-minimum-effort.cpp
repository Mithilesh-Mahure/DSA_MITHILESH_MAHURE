class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    typedef vector<int> vi;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> distance(r, vector<int>(c, INT_MAX));
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        distance[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            auto node_dist = f[0], x = f[1], y = f[2];
            for (int k = 0; k < 4; k++) {
                int newi = x + dx[k];
                int newj = y + dy[k];
                if (newi < 0 || newj < 0 || newi >= r || newj >= c) {
                    continue;
                }
                auto new_distance =
                    max(node_dist, abs(heights[x][y] - heights[newi][newj]));
                if (new_distance < distance[newi][newj]) {
                    distance[newi][newj] = new_distance;
                    pq.push({distance[newi][newj], newi, newj});
                }
            }
        }
        return distance[r - 1][c - 1];
    }
};