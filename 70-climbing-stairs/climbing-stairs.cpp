class Solution {
public:
    vector<int> dp;

    int helper(int sum){
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        return dp[sum]=helper(sum-1)+helper(sum-2);
    }
    
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return helper(n);
    }
};