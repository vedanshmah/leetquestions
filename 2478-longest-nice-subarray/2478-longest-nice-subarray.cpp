class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask=0;
        int maxlen=INT_MIN;
        int start=0;
        for(int end=0;end<nums.size();end++){
            int temp=mask & nums[end];
            while((mask & nums[end])!=0){
                mask=mask^nums[start];
                start++;
            }

            mask=mask |nums[end];
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};