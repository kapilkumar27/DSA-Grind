class Solution {
public:
    vector<int> dp;

    int helper(int i,vector<int>&nums){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(helper(i+1,nums),nums[i]+helper(i+2,nums));
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return helper(0,nums);
    }
};