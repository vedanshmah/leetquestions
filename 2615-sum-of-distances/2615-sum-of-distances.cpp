class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<long long> res(n);

        for(auto &it : mp){
            vector<int> &index = it.second;
            int m = index.size();

            if(m == 1){
                res[index[0]] = 0;
                continue;
            }

            long long totalSum = 0;
            for(int x : index) totalSum += x;

            long long leftSum = 0;

            for(int k = 0; k < m; k++){
                long long curr = index[k];
                long long left = curr * k - leftSum;
                long long right = (totalSum - leftSum - curr) - (m - k - 1) * curr;

                res[curr] = left + right;

                leftSum += curr;
            }
        }

        return res;
    }
};