class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
            if(mp[x]>1) return true;
        }
        return false;
    }
};