class Solution {
public:
    bool solve(vector<int>& candies,int mid ,long long k){
        long long int res=0;
        for(int i=0;i<candies.size();i++){
            res+=candies[i]/mid;
        }
        if(res>=k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int tsum=0;
        int maxc=0;
        for(int i=0;i<candies.size();i++){
            tsum+=candies[i];
            maxc=max(maxc,candies[i]);
        }
        if(tsum<k){
            return 0;
        }
        int ans=0;
        int low=1;
        int high=maxc;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool piles=solve(candies,mid,k);
            if(piles){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
            
        }
        return ans;
    }
};