class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int co=0;
        int n=A.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                co++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                co++;
            }
            res[i]=co;
        }
        return res;
    }
};