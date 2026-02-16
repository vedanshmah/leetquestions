class Solution {
public:
    int reverseBits(int n) {
        int res=0;
        for(int i=0;i<=31;i++){
            int bit = n&1; //extracting bit 
            res=res<<1;       //shifting result 
            res=res|bit;      //adding our extarcted bit to res
            n=n>>1;           //updating n for next iteration
        }
        return res;
    }
};