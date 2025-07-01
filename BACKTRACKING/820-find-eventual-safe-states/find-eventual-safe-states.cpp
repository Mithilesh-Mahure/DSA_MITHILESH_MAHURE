class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& currPath, vector<int>& safe) {
        visited[node] = 1;
        currPath[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, currPath, safe)) {
                    return true;  // cycle detected
                }
            } else if (currPath[nbr]) {
                return true;  // back edge -> cycle
            }
        }

        // backtrack
        currPath[node] = 0;
        safe[node] = 1;  // node is safe
        return false;  // no cycle found
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> currPath(n, 0);
        vector<int> safe(n, 0);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited, currPath, safe);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (safe[i]) result.push_back(i);
        }

        return result;
    }
};
