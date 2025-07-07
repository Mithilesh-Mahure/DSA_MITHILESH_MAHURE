class Solution {
    typedef pair<int,int> pi;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pi>> connections(n);
        vector<int> costing(n,INT_MAX);

        for(auto x:flights){
            connections[x[0]].push_back({x[1],x[2]});
        }

        costing[src]=0;
        queue<vector<int>> pq;
        pq.push({0,src,costing[src]});//stops,node,cost

        while(!pq.empty()){
            auto f=pq.front();
            pq.pop();
            auto stops_taken=f[0];
            auto node_name=f[1];
            auto node_distance=f[2];

            if(stops_taken>k) break;
            for(auto nbr_info:connections[node_name]){
                auto nbr=nbr_info.first;
                auto wt=nbr_info.second;
                auto curr_dist=node_distance+wt;
                if(curr_dist<costing[nbr]){
                    costing[nbr]=curr_dist;
                    pq.push({stops_taken+1,nbr,curr_dist});
                }
            }
        }

        return costing[dst]==INT_MAX?-1:costing[dst];
    }
};