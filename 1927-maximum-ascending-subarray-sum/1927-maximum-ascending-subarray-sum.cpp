class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int currsum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                currsum+=nums[i];
            }
            else{
                ans=max(ans,currsum);
                currsum=nums[i];
            }
        }
        ans=max(ans,currsum);
        return ans;
    }
};