class Solution {
public:
    bool solve(int sq,int currsum,int num){
        if(sq==0){
            return currsum==num;
        }

        return solve(sq/10,currsum+sq%10,num) || solve(sq/100,currsum+sq%100,num) ||
                solve(sq/1000,currsum+sq%1000,num) || solve(sq/10000,currsum+sq%10000,num);

    }
    int punishmentNumber(int n) {
        int res=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;
            if(solve(sq,0,num)==true){
                res+=sq;
            }
        }
        return res;
    }
};