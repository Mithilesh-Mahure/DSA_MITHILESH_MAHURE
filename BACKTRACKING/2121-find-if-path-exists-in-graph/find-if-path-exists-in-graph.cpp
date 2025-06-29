class Solution {
public:
    void dfs(vector<int> &visited,vector<vector<int>> &graph,int node){
        visited[node]=1;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                dfs(visited,graph,nbr);
            }
        }
    }
    void bfs(vector<int> &visited,vector<vector<int>> &graph,int node){
        queue<int> q;
        q.push(node);
        visited[node]=1;

        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int nbr:graph[f]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                }

            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(visited,graph,source);
        return visited[destination];
    }
};