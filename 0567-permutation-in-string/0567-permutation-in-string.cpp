class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(begin(s1),end(s1));
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2){
            return false;
        }
        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);
        for(int i=0;i<n1;i++){
            char ch=s1[i];
            s1freq[ch - 'a']++;
        }
        int i=0,j=0;
        while(j<n2){
            s2freq[s2[j]-'a']++;
            if(j-i+1 > n1){
                s2freq[s2[i]-'a']--;
                i++;
            }

            if(s1freq==s2freq){
                return true;
            }
            j++;
        }
        return false;
    }
};