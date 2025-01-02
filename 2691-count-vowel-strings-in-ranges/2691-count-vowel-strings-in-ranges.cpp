class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> presum;
        vector<int> ans;
        int co=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
                (s[s.length() - 1] == 'a' || s[s.length() - 1] == 'e' || s[s.length() - 1] == 'i' || s[s.length() - 1] == 'o' || s[s.length() - 1] == 'u')) {
                co++;
            }
            presum.push_back(co);
        }
        for(int i=0;i<queries.size();i++){
            int r=queries[i][1];
            int l=queries[i][0];
            int sum;
            if(l>0){
                sum=presum[r]-presum[l-1];
            }
            else{
                sum=presum[r];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};