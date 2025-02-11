class Solution {
public:
    bool check(stack<char> &st,string &part){
        stack<char> temp=st;
        for(int i=part.size()-1;i>=0;i--){
            if(part[i]!=temp.top()){
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        //while(s.length() != 0 && s.find(part) < s.length()){
        //    s.erase(s.find(part) , part.length());
        //}
        //return s;
        //using stack
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(st.size()>=part.size() && check(st,part)){
                for(int i=1;i<=part.size();i++){
                    st.pop();
                }
            }
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};