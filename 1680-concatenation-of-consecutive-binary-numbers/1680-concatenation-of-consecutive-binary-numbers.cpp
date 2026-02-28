class Solution {
public:
    int concatenatedBinary(int n) {
        long int res=0;
        int m=1e9+7;
        for(int i=1;i<=n;i++){
            int bits=log2(i) +1;
            res=(((res<<bits)%m)+i)%m;

        }
        return res;
    }
};
