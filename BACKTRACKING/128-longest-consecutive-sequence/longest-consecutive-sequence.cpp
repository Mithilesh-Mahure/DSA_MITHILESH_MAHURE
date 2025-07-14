class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int cnt =1;
        int maxl =1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1) cnt++;
            else cnt = 1;
            maxl=max(maxl, cnt);
        }
        return maxl;
    }
};