class Solution {
public:
    int helper(int n) {
        if(n == 0) return 1;
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[1][0]=1;
        dp[1][1]=1;
        for(int i=2;i<=n;i++){
            dp[i][0]=dp[i-1][0] + dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
        return dp[n][0]+dp[n][1];
    }
    int findIntegers(int n) {
        int ways=0;
        string bin = bitset<32>(n).to_string();
        bin = bin.substr(bin.find('1'));
        int prevbit=0;
        for(int i=0;i<bin.size();i++){
            if(bin[i]=='1'){
                //for 0
                ways+=helper(bin.size()-i-1);
                if(prevbit==1){
                    return ways;
                }
                prevbit=1;
            }else{
                prevbit=0;
            }
        }
        return ways+1;
    }
};