class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int tuples=0;
        for(auto it:mp){
            int freq=it.second;
            tuples += (freq*(freq-1))/2;
        }
        return tuples*8;
    }
};