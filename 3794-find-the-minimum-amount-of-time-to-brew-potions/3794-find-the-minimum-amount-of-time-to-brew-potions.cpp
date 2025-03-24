class Solution {
public:
    long long minTime(vector<int>& chef, vector<int>& difficulty) {
        int n=chef.size();
        int m=difficulty.size();
        vector<long long int> done(n+1,0);
        for(int i=0;i<m;i++){
            //front--->
            for(int j=0;j<n;j++){
                done[j+1]=max(done[j],done[j+1]) + (long long)chef[j]*difficulty[i];
            }
            //back<----
            for(int j=n-1;j>0;j--){
                done[j]=done[j+1] - (long long)chef[j]*difficulty[i];
            }
        }
        return done[n];
    }
};