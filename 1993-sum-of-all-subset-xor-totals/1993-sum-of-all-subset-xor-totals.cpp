class Solution {
public:
    int ans=0;
    void solve(int index,vector<int>& nums,int temp){
        //base
        if(index >= nums.size()){
            ans+=temp;
            temp=0;
            return;
        }
        //rec
        temp=temp^nums[index];
        solve(index+1,nums,temp);
        temp=temp^nums[index];
        solve(index+1,nums,temp);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0,nums,0);
        return ans;
    }
};