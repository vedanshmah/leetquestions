class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0,maxele=0,maxdiff=0;
        for(int i=0;i<nums.size();i++){
            res=max(res,(long long)maxdiff*nums[i]);
            maxdiff=max(maxdiff,(long long)maxele-nums[i]);
            maxele=max(maxele,(long long)nums[i]);
        }
        return res;
    }
};