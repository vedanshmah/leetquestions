class Solution {
public:
    int numSteps(string s) {
        int co=0;
        int n=s.size();
        while(!(s.size()==1 && s[0]=='1')){
            if(s[s.size()-1]=='0'){
                s.pop_back();
                co++;
            }
            else if(s[s.size()-1]=='1'){
                co++;
                char carry='1';
                for(int i=s.size()-1;i>=0;i--){
                    if(carry=='0'){
                        break;
                    }
                    if(s[i]=='1'){
                        s[i]='0';
                        carry='1';
                    }
                    else{
                        s[i]='1';
                        carry='0';
                    }
                }
                if(carry=='1'){
                    s.insert(s.begin(),'1');
                }
            }
        }
        return co;
    }
};