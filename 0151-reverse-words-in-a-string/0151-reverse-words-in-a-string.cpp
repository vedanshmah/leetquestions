class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.length();
        string ans;

        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            int j=i;
            while(j<n && s[j]!=' '){
                j++;
            }
            string temp=s.substr(i,j-i);
            if(ans.length()==0){
                ans=temp;
            }
            else{
                ans=temp+" "+ans;
            }
            i=j;
        }
        return ans;
    }
};