class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(queries.size(),INT_MAX);
        int n=nums.size();
        for(int i=0;i<queries.size();i++){
            int num=nums[queries[i]];
            int start=queries[i];
            vector<int>& indexes=mp[num];
            if(indexes.size()==1){
                ans[i]=-1;
                continue;
            } 
            else{
                int pos = lower_bound(indexes.begin(), indexes.end(), start) - indexes.begin();
                int next=indexes[(pos+1) % indexes.size()];
                ans[i]=min(ans[i],min(abs(start-next),n-abs(start-next)));

                int prev = indexes[(pos - 1 + indexes.size()) % indexes.size()];
                ans[i] = min(ans[i], min(abs(start - prev), n - abs(start - prev)));
            }
        }
        return ans;
    }
};