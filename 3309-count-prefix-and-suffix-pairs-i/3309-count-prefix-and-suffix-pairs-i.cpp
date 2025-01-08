class Solution {
public:
    bool ispresuf(const string& s1,const string& s2){
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2){
            return false;
        }
        bool ch=true;
        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]){
                ch=false;
            }
        }
        for(int i=0;i<n1;i++){
            if(s1[n1-i-1]!=s2[n2-i-1]){
                ch=false;
            }
        }
        return ch;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n =words.size();
        int co=0;
        //sort(words.begin(),words.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ispresuf(words[i],words[j])){
                    co++;
                }
            }
        }
        return co;
    }
};