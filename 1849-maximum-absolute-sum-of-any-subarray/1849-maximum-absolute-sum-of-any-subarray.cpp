class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
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
        minsum=abs(minsum);
        if(minsum<maxsum){
            return maxsum;
        }
        return minsum;
    }
};