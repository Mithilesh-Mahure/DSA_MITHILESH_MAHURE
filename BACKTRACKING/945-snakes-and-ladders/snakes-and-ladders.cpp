class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> connections(n * n + 1, -1);
        int flag = 1;
        int node = 1;
        // forming Connections array as standard input
        for (int i = n - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) {
                        connections[node] = board[i][j];
                    }
                    node++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        connections[node] = board[i][j];
                    }
                    node++;
                }
            }
            flag = !flag;
        }
        // forming graph
        vector<vector<int>> graph(n * n + 1);
        for (int i = 1; i <= n * n - 1; i++) {
            for (int count = 1; count <= 6; count++) {
                int nbr = i + count;
                if (nbr <= n * n) {
                    if (connections[nbr] != -1) {
                        graph[i].push_back(connections[nbr]);
                    } else {
                        graph[i].push_back(nbr);
                    }
                }
            }
        }
        // BFS TRAVERSAL
        queue<int> q;
        int level = 0;
        vector<int> visited(n * n + 1, 0);
        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int f = q.front();
                q.pop();
                if (f == n * n)
                    return level;
                for (int nbr : graph[f]) {
                    if (!visited[nbr]) {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};