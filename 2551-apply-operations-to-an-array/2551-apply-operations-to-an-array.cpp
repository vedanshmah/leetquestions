class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
                i++;
            }
            i++;
        }
        int index = 0; 
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[index]);
                index++;
            }
        }
        return nums;
    }
};