class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxsum(n);
        maxsum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxsum[i]=max(nums[i],maxsum[i+1]);
        }
        int ans=0;
        int i=0;
        int j=0;
        while(j<n){
            while(i<j && nums[i]>maxsum[j]){
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;


        }
};