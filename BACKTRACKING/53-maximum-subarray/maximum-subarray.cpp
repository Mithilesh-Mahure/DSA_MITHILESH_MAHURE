class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];//take sum starting value
        int res=nums[0]; //initialize res with 1st value
        for(int i=1;i<=nums.size()-1;i++){
            sum=max(nums[i],sum+nums[i]);
            res=max(res,sum);
            //if(sum>res)res=sum;
        }
        return res;
        
    }
};