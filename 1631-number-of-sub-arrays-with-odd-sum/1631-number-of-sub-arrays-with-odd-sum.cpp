class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> presum(n,0);
        presum[0]=arr[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+arr[i];
        }
        int oddco=0;
        int evenco=1;
        int res=0;
        int mod=1000000007;
        for(int i=0;i<n;i++){
            if(presum[i]%2==0){
                res=(res+oddco) % mod;
                evenco++;
            }
            else{
                res=(res+evenco) % mod;
                oddco++;
            }
        }
        return res;
    }
};