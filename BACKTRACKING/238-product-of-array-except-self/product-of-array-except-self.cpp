class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int n=nums.size();
        vector<int> ans(nums.size(),1);
        int prefix=1,suffix=1;
        for(int i=1;i<nums.size();i++){
            ans[i]*=prefix*nums[i-1];
            ans[n-i-1]*=suffix*nums[n-i];

            prefix*=nums[i-1];
            suffix*=nums[n-i];
        }
        return ans;
    }
};