class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long int score=0;
        for(int i=0;i<k;i++){
            int t=pq.top();
            score+=t;
            pq.pop();
            t=ceil(t/3.0);
            pq.push(t);
        }
        return score;
    }
};