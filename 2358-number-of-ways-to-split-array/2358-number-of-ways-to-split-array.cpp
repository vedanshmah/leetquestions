class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int tsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        int res=0;
        long long int presum=0;
        for(int i=0;i<n-1;i++){
            presum+=nums[i];
            long long int postsum=tsum-presum;
            if(presum>=postsum){
                res++;
            }
        }
        return res;
    }
};