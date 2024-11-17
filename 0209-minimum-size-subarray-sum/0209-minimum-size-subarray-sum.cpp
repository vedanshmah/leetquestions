class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int ans=0,res=INT_MAX;;
        while(j<n){
           ans+=nums[j];

           while(ans>=target){
            ans-=nums[i];
            res=min(res,j-i+1);
            i++;
           }
           j++;
        }

        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};