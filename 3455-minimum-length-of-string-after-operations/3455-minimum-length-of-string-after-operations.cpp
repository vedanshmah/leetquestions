class Solution {
public:
    int minimumLength(string s) {
        //unordered_map<char,int> mp;
        //for(char &ch:s){
        //    mp[ch]++;
        //    if(mp[ch]>2){
        //        mp[ch]-=2;
        //    }
        //}
        //int co=0;
        //for(const auto &pair:mp){
        //    co+=pair.second;
        //}
        //return co;

        //using 26 size vector
        vector<int> vec(26,0);
        for(int i=0;i<s.length();i++){
            vec[s[i]-'a']++;
            if(vec[s[i]-'a']>2){
                vec[s[i]-'a']-=2;
            }
        }
        int co=0;
        for(int i=0;i<26;i++){
            if(vec[i]==0){
                continue;
            }
            co+=vec[i];
        }
        return co;
    }
};