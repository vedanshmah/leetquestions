class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                ans.push(ch);
            }
            else if(!ans.empty() && ans.top()=='('){
                ans.pop();
            }
            else{
                ans.push(ch);
            }
        }
        return ans.size();
    }
};