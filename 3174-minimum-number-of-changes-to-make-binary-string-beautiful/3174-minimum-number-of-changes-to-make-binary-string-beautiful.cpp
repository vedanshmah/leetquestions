class Solution {
public:
    int minChanges(string s) {
        int co=0;
        for(int i=0;i<s.length();i=i+2){
            if(s[i]!=s[i+1]){
                co++;
            }
        }
        return co;

    }
};