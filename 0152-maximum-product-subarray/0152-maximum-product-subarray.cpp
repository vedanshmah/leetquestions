class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax=nums[0];
        int currmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempmax=currmax;
            int tempmin=currmin;
            currmax=max(nums[i],max(nums[i]*tempmax,nums[i]*tempmin));
            currmin=min(nums[i],min(nums[i]*tempmax,nums[i]*tempmin));

            ans=max(ans,currmax);
        }
        return ans;
    }
};