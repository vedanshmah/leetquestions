class Solution {
public:
    vector<vector<int>> sub;

    void solve(int index,vector<int>& nums,vector<int>& temp){
        //base
        if(index >= nums.size()){
            sub.push_back(temp);
            return;
        }
        //rec
        temp.push_back(nums[index]);
        solve(index+1,nums,temp);
        temp.pop_back();
        solve(index+1,nums,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums,temp);
        return sub;
    }
};