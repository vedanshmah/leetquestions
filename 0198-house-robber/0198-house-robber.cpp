class Solution {
public:
    int helper(vector<int>& nums,int house, vector<int> &dp){
        //base
        if(house<0){
            return 0;
        }
        if(dp[house]!=-1){
            return dp[house];
        }
        //rec
        int rob_1=nums[house] + helper(nums,house-2,dp);
        int rob_2=helper(nums,house-1,dp);
        dp[house]= max(rob_1,rob_2);
        return dp[house];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,nums.size()-1,dp);
    }
};