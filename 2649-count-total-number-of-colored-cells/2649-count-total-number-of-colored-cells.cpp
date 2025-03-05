class Solution {
public:
    long long solve(int n,long long res){
        //base
        if(n==1){
            return 1;
        }
        //rec
        long long temp=solve(n-1,res);
        res=((4*n)-4)+temp;
        return res;
    }
    long long coloredCells(int n) {
        long long res;
        return solve(n,res);
    }
};