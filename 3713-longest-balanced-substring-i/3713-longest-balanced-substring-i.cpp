class Solution {
public:
    int longestBalanced(string s) {
        int maxl=0;
        for(int l=0;l<s.size();l++){
            unordered_map<char,int> mp;
            for(int r=l;r<s.size();r++){
                mp[s[r]]++;
                bool bal=true;
                int freq=mp.begin()->second;
                for(auto&obj :mp){
                    if(obj.second != freq){
                        bal=false;
                        break;
                    }
                }
                if(bal){
                    maxl=max(maxl,r-l+1);
                }
            }
        }
        return maxl;
    }
};