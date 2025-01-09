class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int n1=pref.size();
        int co=0;
        for(int i=0;i<n;i++){
            string s1=words[i];
            if(s1.substr(0,n1)==pref){
                co++;
            }
        }
        return co;
    }
};