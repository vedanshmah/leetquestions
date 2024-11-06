class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();

        for(int times=0;times<n;times++){
            for(int j=0;j<n-1-times;j++){
                if(nums[j]<=nums[j+1]){
                    continue;
                }
                else{
                    if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
                        swap(nums[j],nums[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};