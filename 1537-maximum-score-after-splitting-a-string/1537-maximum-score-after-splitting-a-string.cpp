class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int co1=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                co1++;
            }
        }  
        int co0=0;
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                co0++;
            }
            if(s[i]=='1'){
                co1--;
            }
            ans=max(ans,co1+co0);
        }
        return ans;
    }
};