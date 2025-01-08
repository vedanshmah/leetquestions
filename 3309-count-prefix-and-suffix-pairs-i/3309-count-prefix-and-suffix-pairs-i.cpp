class Solution {
public:
    bool ispresuf(const string& s1,const string& s2){
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2){
            return false;
        }
        if(s2.substr(0,n1)==s1){
            if(s2.substr(n2-n1)==s1){
                return true;
            }
        }
        return false;
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