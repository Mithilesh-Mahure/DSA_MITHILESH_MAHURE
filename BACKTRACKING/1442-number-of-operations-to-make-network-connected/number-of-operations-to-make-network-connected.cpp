class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool> &visited,int src){
        visited[src]=true;
        for(int i:graph[src]){
            if(!visited[i]){
                dfs(graph,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        if(connections.size()<n-1) return -1;
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int components=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,i);
                components++;
            }
        }
        return components;
    }
};