class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, int parent, vector<int>& ans) {
        visited[node] = 1;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, node, ans)) {
                    return true;
                }
            } else if (nbr != parent) {
                ans = {nbr,node};
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1);
        vector<int> ans = {0, 0};

        for (int i = 0; i < n; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);

            fill(visited.begin(), visited.end(), 0); // reset visited before each DFS
            if (dfs(a, graph, visited, -1, ans)) {
                return ans;
            }
        }

        return ans;
    }
};
