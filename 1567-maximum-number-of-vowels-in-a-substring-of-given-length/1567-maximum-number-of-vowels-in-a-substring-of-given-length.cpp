class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels={'a','e','i','o','u'};
        int currco=0;
        int maxco=0;
        for(int i=0;i<k;i++){
            if(vowels.find(s[i])!=vowels.end()){
                currco++;
            }
        }
        maxco=currco;
        int i=k;
        while(i<s.size()){
            if(vowels.find(s[i-k]) != vowels.end()){
                currco--;
            }
            if(vowels.find(s[i])!=vowels.end()){
                currco++;
            }
            maxco=max(maxco,currco);
            i++;
        }
        return maxco;
    }
};