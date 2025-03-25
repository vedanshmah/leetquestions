class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        //-4 -1 -1 0 1 2
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j]==nums[j-1] && j<k){
                        j++;
                    }
                }
                else if(sum>0){
                    k--;
                }
            }
        }
        return res;
    }
};