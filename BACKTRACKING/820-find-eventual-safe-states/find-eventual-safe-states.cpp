class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& curr, vector<int>& safe) {
        visited[node]=1;
        curr[node]=1;
        for(auto nbr:graph[node]){
            if(!visited[nbr]){
                if (dfs(nbr, graph, visited, curr, safe)){
                    return true;
                }
            }else if(curr[nbr]){
                return true;
            }
        }
        curr[node]=0;
        safe[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), curr(n, 0), safe(n, 0),res;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, curr, safe);
            }
        }
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};