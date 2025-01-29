class Solution {
public:
    double helper(double x,int n){
        if(n==0){
            return 1.0;
        }
        
        double temp=helper(x,n/2);
        return (n%2==0)? temp*temp : temp*temp*x;
    }
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        
        if(n<0){
            return (1/helper(x,n));
        }
        return helper(x,n);
    }
};