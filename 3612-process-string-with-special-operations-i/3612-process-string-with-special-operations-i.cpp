class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char &ch:s){
            if(ch>='a' && ch<='z'){
                res.push_back(ch);
            }else if(ch=='*' && res.size()>0){
                res.erase(res.size()-1,1);
            }else if(ch=='#'){
                res+=res;
            }else if(ch=='%'){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};

