class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0,i=0;
        while(i<n){
            char ch=chars[i];
            int co=0;
            while(i<n && chars[i]==ch){
                co++;
                i++;
            }

            chars[idx]=ch;
            idx++;

            if(co>1){
                string count=to_string(co);
                for(char &c:count){
                    chars[idx]=c;
                    idx++;
                }
            }
        }
        return idx;
    }
};