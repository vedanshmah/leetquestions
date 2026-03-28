class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024,false)));
        
        dp[0][0][grid[0][0]]=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int xorv=0;xorv<1024;xorv++){
                    if (dp[i][j][xorv]==true){
                        if(j+1<n){
                            int newxor=xorv ^ grid[i][j+1];
                            dp[i][j+1][newxor]=true;
                        }
                        if(i+1<m){
                            int newxor=xorv ^ grid[i+1][j];
                            dp[i+1][j][newxor]=true;
                        }
                    }
                }
            }
        }
        for(int xorVal = 0; xorVal < 1024; xorVal++){
            if(dp[m-1][n-1][xorVal]){
                return xorVal;
            }
        }

        return -1;
    }
};