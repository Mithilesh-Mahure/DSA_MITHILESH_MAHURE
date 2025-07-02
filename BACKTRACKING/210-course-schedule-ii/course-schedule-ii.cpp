class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> ans;
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for(auto &edge:prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(graph[i].empty()) continue;
            for(int &x:graph[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int &nbr:graph[f]){
                indegree[nbr]--;
                if(!indegree[nbr])
                    q.push(nbr);
            }
        }
        if(ans.size()==n){
            return ans;
        }else{
            return {};
        }
    }
};