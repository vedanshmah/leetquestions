class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int> st;
        string res="";
        int co=1;
        for(int i=0;i<=n;i++){
            st.push(co);
            co++;
            if(i==n || pattern[i]=='I'){
                while(!st.empty()){
                    char num=st.top()+'0';
                    st.pop();
                    res+=num;
                }
            }
        }
        return res;
    }
};