class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> evenmp(26,0);
        vector<int> oddmp(26,0);
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                evenmp[s1[i]-'a']++;
                evenmp[s2[i]-'a']--;
            }else{
                oddmp[s1[i]-'a']++;
                oddmp[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(evenmp[i]!=0 || oddmp[i]!=0){
                return false;
            }
        }
        return true;
    }
};