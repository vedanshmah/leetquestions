class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> res(n);
        int maxor=0;
        for(int i=0;i<n;i++){
            maxor=maxor^nums[i];
        }
        
        int mask=((1<<maximumBit)-1);

        for(int i=0;i<n;i++){
            int ans=maxor ^mask;
            res[i]=ans;
            maxor=maxor^nums[n-i-1];
        }
        return res;

    }
};