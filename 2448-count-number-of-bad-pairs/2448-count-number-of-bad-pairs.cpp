class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        unordered_map <int,int> mp;
        mp[nums[0]]=1;
        for(int i=1;i<n;i++){ 
            int countof_prev_i=mp[nums[i]];
            int totalpairs=i;
            int badpairs=totalpairs-countof_prev_i;
            result+=badpairs;
            mp[nums[i]]++;
        }
        return result;
    }
};