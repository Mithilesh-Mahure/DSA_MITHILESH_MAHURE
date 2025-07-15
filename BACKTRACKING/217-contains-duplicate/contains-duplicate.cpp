class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            if(mp[x]>=1) return true;
            mp[x]++;
        }
        return false;
    }
};