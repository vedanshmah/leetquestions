class Solution {
public:
    void solve(string s,set<string>& st,int i,int& maxco,int currco){
        if(i>=s.length()){
            maxco=max(maxco,currco);
            return;
        }

        for(int j=i;j<s.length();j++){
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(s,st,j+1,maxco,currco+1);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        int maxco=0;
        int currco=0;
        solve(s,st,0,maxco,currco);
        return maxco;
    }
};