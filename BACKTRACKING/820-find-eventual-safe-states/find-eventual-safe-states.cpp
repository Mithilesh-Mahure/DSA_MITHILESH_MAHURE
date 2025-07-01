class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& currPath, vector<int>& safe) {
        visited[node] = 1;
        currPath[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, currPath, safe)) {
                    return true;  // cycle found
                }
            } else if (currPath[nbr]) {
                return true;  // back edge -> cycle
            }
        }

        currPath[node] = 0;
        safe[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;

        // Declare all 3 tracking vectors within the loop for first-time initialization
        vector<int> visited(n, 0), currPath(n, 0), safe(n, 0);

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