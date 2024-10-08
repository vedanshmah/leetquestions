class Solution {
public:
    int minSwaps(string s) {
        stack<char> ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='['){
                ans.push(ch);
            }
            else if(!ans.empty()){
                ans.pop();
            }
        }
        return (ans.size()+1)/2;
    }
};