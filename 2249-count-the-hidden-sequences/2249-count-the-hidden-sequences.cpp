class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long int> presum(n + 1, 0);  
        presum[1] = nums[0];
        for (int i = 1; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        
        long long maxvalue = LLONG_MIN, minvalue = LLONG_MAX;  
        for (auto x : presum) {
            maxvalue = max(maxvalue, (long long)x); 
            minvalue = min(minvalue, (long long)x);  
        }
        
        long long ll = (long long)lower - minvalue;  
        long long ul = (long long)upper - maxvalue;  
        
        return max(0LL, ul - ll + 1); 
    }
};
