class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums,int idx,int sum,int tsum){
        //base
        if(sum==tsum){
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        if(t[idx][sum]!=-1){
            return t[idx][sum];
        }
        //rec
        bool take=solve(nums,idx+1,sum+nums[idx],tsum);
        bool nottake=solve(nums,idx+1,sum,tsum);
        return t[idx][sum]=(take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(auto i:nums){
            tsum+=i;
        }
        if(tsum%2!=0){
            return false;
        }
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,tsum/2);
    }
};