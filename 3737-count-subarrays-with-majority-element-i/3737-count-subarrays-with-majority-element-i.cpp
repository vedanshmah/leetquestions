class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int co=0;
        for(int i=0;i<nums.size();i++){
            int freq=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                    freq++;
                }
                int len=j-i+1;
                if((len/2) < freq){
                    co++;
                }
            }
        }
        return co;
    }
};