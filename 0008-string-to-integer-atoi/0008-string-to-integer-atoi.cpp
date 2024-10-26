class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int MAX=INT_MAX,MIN=INT_MIN;
        while(i<s.length() and s[i]==' '){
            i++;
        }
        s=s.substr(i);
        
        int sign=1;
        long long int ans=0;

        if(s[0]=='-'){
            sign=-1;
        }
        
        
        if(s[0]=='+' || s[0]=='-'){
            i=1;
        }
        else{
            i=0;
        }

        while(i<s.length()){
            if(!(s[i]>='0' and s[i]<='9') || s[i]==' '){
                break;
            }
            ans=ans*10 + (s[i]-'0');
            if(sign==-1 and -1*ans<MIN){
                return MIN;
            }
            if(sign==1 and ans>MAX){
                return MAX;
            }
            i++;
        }
        
        int sol=ans*sign;
        return sol;

    }
};