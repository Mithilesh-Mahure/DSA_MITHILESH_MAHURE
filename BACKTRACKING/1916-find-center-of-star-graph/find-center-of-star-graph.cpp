class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>graph(n+2);

        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            graph[a]++;
            graph[b]++;
        }

        for(int i=1;i<=n+1;i++){
            if(graph[i]==(n)) return i;
        }
        return -1;
    }
};