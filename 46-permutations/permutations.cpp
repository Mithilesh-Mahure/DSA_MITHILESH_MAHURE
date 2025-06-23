class Solution {
public:
    void permute(vector<int> ip,vector<int> op,vector<vector<int>> &v){
        if(ip.size()==0){
            v.push_back(op);
            return;
        }
        unordered_set<int> mp;
        for(int i=0;i<ip.size();i++){
            if(mp.find(ip[i])==mp.end()){
                mp.insert(ip[i]);
                vector<int> newIP(ip.begin(),ip.begin()+i);
                newIP.insert(newIP.end(),ip.begin()+i+1,ip.end());
                vector<int> newOP=op;
                newOP.push_back(ip[i]);
                permute(newIP,newOP,v);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size()==1){
            v.push_back(nums);
            return v;
        }

        permute(nums,{},v);
        return v;
    }
};