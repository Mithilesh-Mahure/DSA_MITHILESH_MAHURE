class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& visited) {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nbr : graph[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    q.push({nbr, node});
                } else if (nbr != parent) {
                    return true; // cycle detected
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            vector<int> visited(n + 1, 0);
            if (bfs(u, graph, visited)) {
                return {u, v}; // the edge that caused the cycle
            }
        }

        return {};
    }
};
