class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> res(n,0.0);
        res[start_node]=1.0;
        for(int i=0;i<n-1;i++){
            auto index=0;
            bool changed=false;
            vector<double> temp = res;  // Snapshot for current iteration
            for(auto edge:edges){
                auto node= edge[0];
                auto nbr= edge[1];
                auto wt=succProb[index++];

                if(res[nbr]<temp[node]*wt){
                    res[nbr]=temp[node]*wt;
                    changed=true;
                }
                if(res[node]<temp[nbr]*wt){
                    res[node]=temp[nbr]*wt;
                    changed=true;
                }
            }
            if (!changed) break;  // early stopping if no updates

        }
        return res[end_node];
    }
};