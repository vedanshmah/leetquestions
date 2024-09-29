class Solution {
public:
    int reverse(int x) {
        int rem,sum=0;
        while(x){
            rem = x%10;
            if((sum > INT_MAX/10) || (sum < INT_MIN/10)){
                return 0;
            }
            sum = (sum*10) + rem;
            x/=10;

        }
        
        return sum;
    }
};