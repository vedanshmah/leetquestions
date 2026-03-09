class Solution {
public:
    int M=1e9 + 7;
    int dp[201][201][2];
    int helper(int onesleft,int zeroesleft,bool lastwasone,int limit){
        //base
        if(onesleft==0 && zeroesleft==0){
            return 1;
        }
        if(dp[onesleft][zeroesleft][lastwasone]!=-1){
            return dp[onesleft][zeroesleft][lastwasone];
        }
        int res=0;
        //rec
        if(lastwasone){
            for(int len=1;len<=min(limit,zeroesleft);len++){
                res=(res+helper(onesleft,zeroesleft-len,false,limit)) % M;
            }
        }
        if(!lastwasone){
            for(int len=1;len<=min(limit,onesleft);len++){
                res=(res+helper(onesleft-len,zeroesleft,true,limit)) % M;
            }
        }
        return dp[onesleft][zeroesleft][lastwasone]=res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startwithone=helper(one,zero,false,limit);
        int startwithzero=helper(one,zero,true,limit);
        return (startwithone+startwithzero)%M;
    }
};