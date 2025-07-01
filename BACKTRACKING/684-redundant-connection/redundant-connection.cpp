class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited,vector<int>& parent) {
        queue<int> q;
        visited[node]=1;
        q.push(node);

        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int nbr:graph[f]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    parent[nbr]=f;
                    q.push(nbr);
                } else if(parent[f]!=nbr){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n + 1);

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            vector<int> visited(n + 1, 0), parent(n + 1, -1);
            graph[a].push_back(b);
            graph[b].push_back(a);
            if (bfs(a, graph, visited, parent)) {
                return edge;
            }
        }
        return {};
    }
};