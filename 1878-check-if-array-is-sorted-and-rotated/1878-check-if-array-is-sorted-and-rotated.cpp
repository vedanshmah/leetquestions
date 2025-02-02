class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int co=0;
        if(nums[n-1]>nums[0]){
            co++;
        }
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                co++;
            }
        }
        if(co>1){
            return false;
        }
        return true;
    }
};