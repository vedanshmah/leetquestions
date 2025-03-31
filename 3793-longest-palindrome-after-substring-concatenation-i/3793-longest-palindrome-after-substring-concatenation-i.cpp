class Solution {
public:
    vector<string> gensubstrings(string &str){
        vector<string> temp;
        for(int i=0;i<=str.size();i++){
            for(int j=i;j<=str.size();j++){
                temp.push_back(str.substr(i,j-i));
            }
        }
        return temp;
    }
    int longestPalindrome(string s, string t) {
        vector<string> substofa=gensubstrings(s);
        vector<string> substoft=gensubstrings(t);
        int maxlen=0;
        for(string &ssub:substofa){
            for(string &tsub:substoft){
                string combine=ssub+tsub;
                string rev=combine;
                reverse(rev.begin(), rev.end());
                if(combine==rev){
                    maxlen=max(maxlen,(int)combine.size());
                }
            }
        }
        return maxlen;
    }
};