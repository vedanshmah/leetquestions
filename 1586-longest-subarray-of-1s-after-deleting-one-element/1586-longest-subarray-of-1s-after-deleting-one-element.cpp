class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int start=0,zeroco=0,res=0;

        for(int end=0;end<nums.size();end++){
            if(nums[end]==0){
                zeroco++;
            }

            while(zeroco>1){
                if(nums[start]==0){
                    zeroco--;
                }
                start++;
            }

            res=max(res,end-start);
        }
        return res;
    }
};