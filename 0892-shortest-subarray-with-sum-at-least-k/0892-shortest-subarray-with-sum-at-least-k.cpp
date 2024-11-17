class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<long long int> csum(n,0);
        int res=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                csum[j]=nums[j];
            }
            else{
                csum[j]=csum[j-1]+nums[j];
            }
            if(csum[j]>=k){
                res=min(res,j+1);
            }
            while(!dq.empty() && csum[j]-csum[dq.front()]>=k){
                res=min(res,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && csum[j]<=csum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};