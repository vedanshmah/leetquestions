class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<char> letters;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }
        int res=0;
        for(char letter:letters){
            //char letter=letters[i];
            int l_idx=-1;
            int r_idx=-1;
            for(int j=0;j<n;j++){
                if(s[j]==letter){
                    if(l_idx==-1){
                        l_idx=j;
                    }
                    r_idx=j;
                }
            }

            unordered_set<char> count;
            for(int a=l_idx+1;a<r_idx;a++){
                count.insert(s[a]);
            }
            res+=count.size();
        }
        return res;
    }
};