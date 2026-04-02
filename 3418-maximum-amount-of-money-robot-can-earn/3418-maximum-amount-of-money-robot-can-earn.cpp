class Solution {
public:
    int m;
    int n;
    int dp[501][501][3];
    int solve(vector<vector<int>>& coins , int i,int j , int k){
        //base
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 and k>0){
                return 0;
            }
            return coins[i][j];
        }
        if(i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j][k] != INT_MIN) {
            return dp[i][j][k];
        }
        //rec
        int take=coins[i][j] + max(solve(coins,i,j+1,k) , solve(coins,i+1,j,k));
        int skip=INT_MIN;
        if(coins[i][j]<0 and k>0){
            int skipd=solve(coins,i+1,j,k-1);
            int skipr=solve(coins,i,j+1,k-1);
            skip=max(skipd,skipr);
        }
        return dp[i][j][k]=max(take,skip);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins,0,0,2);
    }
};