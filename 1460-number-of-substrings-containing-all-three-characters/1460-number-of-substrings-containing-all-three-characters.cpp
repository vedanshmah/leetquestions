class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<int> abc(3,0);
        int i=0;
        int j=0;
        while(j<n){
            char ch=s[j];
            abc[ch-'a']++;
            while(abc[0]>0 && abc[1]>0 && abc[2]>0){
                res+=(n-j);
                char chh=s[i];
                abc[chh-'a']--;
                i++;
            }
            j++;
        }
        return res;
    }
};