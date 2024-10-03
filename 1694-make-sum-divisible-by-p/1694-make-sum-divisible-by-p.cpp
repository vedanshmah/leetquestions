class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int,int> mp;
        mp[0]=-1;
        int pre_sum=0;
        int ans=nums.size();
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum=(tsum+nums[i])%p;
        }
        if(tsum==0){
            return 0;
        }

        for(int i=0;i<nums.size();i++){
            pre_sum=(pre_sum+nums[i])%p;
            int check=(pre_sum - tsum +p)%p;
            if(mp.find(check)!=mp.end()){
                ans=min(ans,i-mp[check]);
            }
            mp[pre_sum]=i;
        }
        if(ans==nums.size()){
            return -1;
        }
        return ans;
    }
};