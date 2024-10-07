class Solution {
public:
    int minLength(string s) {
        stack<int> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B' && ans.size()>0 && ans.top()=='A'){
                ans.pop();
            }
            else if(s[i]=='D' && ans.size()>0 && ans.top()=='C'){
                ans.pop();
            }
            else{
                ans.push(s[i]);
            }
        }
        return ans.size();
    }
};