class Solution {
public:
    double dp[101][101];
    double helper(int poured,int i,int j){
        //base
        if(i<j || j<0 ||i<0){
            return 0.0;
        }
        if(i==0 && j==0){
            return poured;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //rec
        double left_up=(helper(poured,i-1,j-1) -1)/2.0;
        double right_up=(helper(poured,i-1,j) -1)/2.0;
        if(left_up<0){
            left_up=0;
        }
        if(right_up<0){
            right_up=0;
        }
        return dp[i][j]=left_up+right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return min(1.0,helper(poured,query_row,query_glass));
    }
};