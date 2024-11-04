class Solution {
public:
    string compressedString(string word) {
        string comp="";
        char co='1';
        for(int i=0;i<word.length();i++){
            if(word[i]==word[i+1] && co<'9'){
                co++;
            }
            else{
                comp.push_back(co);
                comp.push_back(word[i]);
                co='1';
            }
        }
        return comp;
    }
};