class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int i=0,j=0;
        unordered_map<int,int> mp;
        int ans=0;
        for(auto num:nums){
            st.insert(num);
        }
        int k=st.size();
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==k){
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
