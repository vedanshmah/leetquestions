class Solution {
public:
    void rev(vector<int>& nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        rev(nums,0,n-1-k);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
    }
};