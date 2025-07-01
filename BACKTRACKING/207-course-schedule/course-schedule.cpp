class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited,vector<int>& curr) {
       visited[node] = 1;
       curr[node]=1;
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, graph, visited, curr)) {
                    return true;
                }
            } else if (1 == curr[nbr]) {
                return true;
            }
        }
        curr[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        int n=numCourses;
        vector<vector<int>> graph(n+1);

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            vector<int> visited(n+1, 0), curr(n+1, 0);
            graph[a].push_back(b);
            if (dfs(a, graph, visited, curr)) {
                return false;
            }
        }
        return true;
    }
};