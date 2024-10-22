class Solution {
public:
    vector<string> ans;
    void key2(string &target, string &str, int i) {
        while (target[i] != str[i]) {
            if (str[i] == 'z') {
                str[i] = 'a';
            } else {
                str[i]++;  
            }
            ans.push_back(str); 
        }
    }

    vector<string> stringSequence(string target) {
        
        string str;
        for(int i=0;i<target.length();i++){
            str+='a';
            ans.push_back(str);
            if(target[i]!='a'){
                key2(target,str,i);
            }

        }
        return ans;
    }
};