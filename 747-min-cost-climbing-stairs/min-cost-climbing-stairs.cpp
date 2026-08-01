class Solution {
public:
    vector<int> dp;
    int helper(int i,vector<int> &cost){
        int n=cost.size();
        if(i==n){
            return 0;
        }
        if(i>n){
            return 1e9;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i] + min(helper(i+1,cost),helper(i+2,cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size()+1,-1);
        return min(helper(0,cost),helper(1,cost));
    }
};