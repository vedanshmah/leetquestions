class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int,vector<long long int>, greater<long long int>> pq(begin(nums),end(nums));
        
        int co=0;
        while(pq.top()<k){
            long long int n1=pq.top();
            pq.pop();
            long long int n2=pq.top();
            pq.pop();
            long long int temp=(2*n1)+n2;
            pq.push(temp);
            co++;
        }
        return co;
    }
};