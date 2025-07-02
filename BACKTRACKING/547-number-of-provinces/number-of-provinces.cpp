class Solution {
public:
    void dfs(int node,vector<int> &visited,vector<vector<int>>& graph){
        visited[node]=1;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n+1,0);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,graph);
                count++;
            }
        }
        return count;
    }
};