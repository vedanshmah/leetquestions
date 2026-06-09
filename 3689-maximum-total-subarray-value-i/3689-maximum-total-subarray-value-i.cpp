class Solution {
    typedef long long ll;
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int tmax=INT_MIN;
        int tmin=INT_MAX;
        ll val=0;
        ll ans=0;
        for(int i=0;i<nums.size();i++){
            tmax=max(tmax,nums[i]);
            tmin=min(tmin,nums[i]);
        }
        val=tmax-tmin;
        ans=val*k;
        return ans;
    }
};