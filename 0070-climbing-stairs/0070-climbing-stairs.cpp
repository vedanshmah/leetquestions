class Solution {
public:
int nstaircase(int n,int*dp){
    //base
    if(n<0){
        return 0;
    }
    if(n==0){
        return dp[n]=1;
    }
    //check
    if(dp[n]!=-1){
        return dp[n];
    }
    //rec
    return dp[n]=nstaircase(n-1,dp)+nstaircase(n-2,dp);
}
    int climbStairs(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        return nstaircase(n,dp);
    }
};