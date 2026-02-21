class Solution {
public:
    bool primeornot(int n){
        if(n<=1){
            return false;
        }
        int temp=2;
        while(temp<=n-1){
            if(n%temp==0){
                return false;
            }
            temp++;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int co=0;
        for(int i=left;i<=right;i++){
            int setbits=__builtin_popcount(i);
            if(primeornot(setbits)){
                co++;
            }
        }
        return co;
    }
};