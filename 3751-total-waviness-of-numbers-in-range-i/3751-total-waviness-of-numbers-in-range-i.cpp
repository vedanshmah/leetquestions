class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        if(num1<100 && num2<100) return 0;
        if(num1<100 && num2>100){
            num1=100;
        }
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int j=1;j<(int)s.size()-1;j++){
                if(s[j-1]<s[j] && s[j+1]<s[j]){
                    ans++;
                }else if(s[j-1]>s[j] && s[j+1]>s[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};


