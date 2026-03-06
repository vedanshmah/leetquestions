class Solution {
public:
    bool checkOnesSegment(string s) {
        int idx=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                idx=i;
                break;
            }
        }
        if(idx==-1) return true;
        for(int i=idx;i<s.size();i++){
            if(s[i]=='1'){
                return false;
            }
        }
        return true;
    }
};