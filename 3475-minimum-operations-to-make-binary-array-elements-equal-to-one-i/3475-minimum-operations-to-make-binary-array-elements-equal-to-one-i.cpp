class Solution {
public:
    int minOperations(vector<int>& nums) {
        int co=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i-2]==0){
                co++;
                nums[i-2]=nums[i-2]^1;
                nums[i-1]=nums[i-1]^1;
                nums[i]=nums[i]^1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return co;
    }
};