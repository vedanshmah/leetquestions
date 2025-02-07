class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,zeroco=0,res=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==0){
                zeroco++;
            }
            while(zeroco>k){
                if(nums[start]==0){
                    zeroco--;
                }
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};