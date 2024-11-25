class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
        }

        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }

        int minsum=INT_MAX;
        currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            minsum=min(minsum,currsum);
            if(currsum>0){
                currsum=0;
            }
        }
        if(maxsum>0){
            return max(maxsum,tsum-minsum);
        }
        return maxsum;
    }
};