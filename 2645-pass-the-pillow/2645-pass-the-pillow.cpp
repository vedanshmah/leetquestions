class Solution {
public:
    int passThePillow(int n, int time) {
        int ans;
        if(n > time){
            ans = time + 1;
        }
        else if(n <= time){
            int ro = time / (n-1);
            int ex = time % (n-1);
            if(ro % 2 == 0){
                ans = ex +1;
            }
            else{
                ans = n - ex;
            }
        }
        return ans;
    }
};