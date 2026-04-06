class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        if (n == 3) {
            int mx = max(nums[0], nums[2]);
            return max(0, mx + 1 - nums[1]);
        }
        vector<long long> cost(n, 0);
        for (int i = 1; i < n - 1; i++) {
            int mx = max(nums[i - 1], nums[i + 1]);
            cost[i] = max(0, mx + 1 - nums[i]);
        }
        if (n % 2 != 0) {
            long long totalCost = 0;
            for (int i = 1; i < n - 1; i += 2) {
                totalCost += cost[i];
            }
            return totalCost;
        }
        else {
            long long currentCost = 0;
            for (int i = 1; i < n - 1; i += 2) {
                currentCost += cost[i];
            }
            long long minCost = currentCost;
            for (int i = n - 3; i >= 1; i -= 2) {
                currentCost = currentCost - cost[i] + cost[i + 1];
                minCost = min(minCost, currentCost);
            }
            return minCost;
        }
    }
};