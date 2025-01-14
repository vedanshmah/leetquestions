class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //unordered_map<int,int> mp;
        //int co=0;
        //int n=A.size();
        //vector<int> res(n);
        //for(int i=0;i<n;i++){
        //    mp[A[i]]++;
        //    if(mp[A[i]]==2){
        //        co++;
        //    }
        //    mp[B[i]]++;
        //    if(mp[B[i]]==2){
        //        co++;
        //    }
        //    res[i]=co;
        //}
        //return res;
        int n = A.size();
        vector<bool> seen(51, false);
        vector<int> ans;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if (seen[A[i]]) {
                ++common;
            } else {
                seen[A[i]] = true;
            }

            if (seen[B[i]]) {
                ++common;
            } else {
                seen[B[i]] = true;
            }

            ans.push_back(common);
        }

        return ans;
    }
};