class Solution {
public:
    long long minimumSteps(string s) {
        int l=0;
        //r=0;
        long long int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ans=ans+(i-l);
                l++;
            }
           // r++;
            
        }
        return ans;
    }
};