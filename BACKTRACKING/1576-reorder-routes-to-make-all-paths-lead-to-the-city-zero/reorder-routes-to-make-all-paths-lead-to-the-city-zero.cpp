class Solution {
public:
    void dfs(int node, vector<vector<int>>& forward,vector<vector<int>>& backward, int& res, vector<int>& visited) {
        visited[node]=1;
        for(int nbr:forward[node]){
            if(!visited[nbr]){
                res+=1;
                dfs(nbr,forward,backward,res,visited);
            }
        }
        for(int nbr:backward[node]){
            if(!visited[nbr]){
                dfs(nbr,forward,backward,res,visited);
            }
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<int>> forward(n), backward(n);

        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        int res = 0;
        dfs(0, forward, backward, res, visited);
        return res;
    }
};