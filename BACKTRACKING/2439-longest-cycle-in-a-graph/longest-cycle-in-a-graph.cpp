class Solution {
public:
    int lenLongestCycle=-1;
    void dfs(int cyc_len,int node,vector<int>& curr,vector<int>& visited,vector<int>& edges){
        visited[node]=1;
        cyc_len++;
        curr[node]=cyc_len;
        int nbr=edges[node];
        if(nbr!=-1){
            if(!visited[nbr]){
                dfs(cyc_len,nbr,curr,visited,edges);
            } else if(curr[nbr]!=0){
                int curr_cycle_len=curr[node]-curr[nbr]+1;
                lenLongestCycle=max(lenLongestCycle,curr_cycle_len);
            }
        }
        curr[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0);
        vector<int> curr(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(0,i,curr,visited,edges);
            }
        }
        return lenLongestCycle;
    }
};