class Solution {
public:
    char findKthBit(int n, int k) {
        int length=pow(2,n)-1;
        if(n==1){
            return '0';
        }
        if(k<ceil(length/2.0)){
            return findKthBit(n-1,k);
        }
        else if(k==ceil(length/2.0)){
            return '1';
        }
        else{
            char ch=findKthBit(n-1,length-k+1);
            if(ch=='1'){
                return '0';
            }
            else{
                return '1';
            }
        }
    }
};