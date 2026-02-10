class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(ans>=n-i){
                    return ans;
                }
            unordered_set<int> oddset;
            unordered_set<int> evenset;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    evenset.insert(nums[j]);
                }
                else{
                    oddset.insert(nums[j]);
                }
                if(oddset.size()==evenset.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
