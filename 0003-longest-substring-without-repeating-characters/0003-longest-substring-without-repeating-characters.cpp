class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int left=0;
        int res=0;
        for(int right=0;right<s.size();right++){
            if(st.count(s[right])==0){
                st.insert(s[right]);
                res=max(res,right-left+1);
            }
            else{
                while(st.find(s[right])!=st.end()){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
        }
        return res;
    }
};