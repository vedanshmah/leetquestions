class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            mp[val]=i;
        }

        int res=INT_MAX;
        for(int row=0;row<m;row++){
            int lastidx=INT_MIN;
            for(int col=0;col<n;col++){
                int val=mat[row][col];
                int idx=mp[val];
                lastidx=max(lastidx,idx);
            }
            res=min(res,lastidx);
        }

        for(int col=0;col<n;col++){
            int lastidx=INT_MIN;
            for(int row=0;row<m;row++){
                int val=mat[row][col];
                int idx=mp[val];
                lastidx=max(lastidx,idx);
            }
            res=min(res,lastidx);
        }
        return res;
    }
};