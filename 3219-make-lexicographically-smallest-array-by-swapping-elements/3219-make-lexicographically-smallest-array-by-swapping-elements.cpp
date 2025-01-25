class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> vec=nums;
        sort(vec.begin(),vec.end());
        int grpno=0;

        unordered_map<int,int> numtogrp;
        numtogrp[vec[0]]=grpno;

        unordered_map<int,list<int>> grp;
        grp[grpno].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i-1]-vec[i])>limit){
                grpno++;
            }
            numtogrp[vec[i]]=grpno;
            grp[grpno].push_back(vec[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int group=numtogrp[nums[i]];
            res.push_back(*grp[group].begin());
            grp[group].pop_front();
        }
        return res;
    }
};