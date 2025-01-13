class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char &ch:s){
            mp[ch]++;
            if(mp[ch]>2){
                mp[ch]-=2;
            }
        }
        int co=0;
        for(const auto &pair:mp){
            co+=pair.second;
        }
        return co;
        
    }
};