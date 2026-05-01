class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> occur;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
                freq[ch]++;
                if(occur.find(ch)==occur.end()){
                    occur[ch]=i;
                }
            }
        }
        vector<pair<char, pair<int,int>>> v;
        for(auto &p : freq){
            char c = p.first;
            v.push_back({c, {p.second, occur[c]}});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.second.first != b.second.first)
                return a.second.first > b.second.first; 
            return a.second.second < b.second.second;   
        });
        vector<char> temp;
        for(auto &p : v){
            char c = p.first;
            int f = p.second.first;
            for(int i = 0; i < f; i++){
                temp.push_back(c);
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
                s[i]=temp[j++];
            }
        }
        return s;
    }
};