class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        int co_a=0,co_b=0,co_c=0;
        //pehle a b c ka count nikalo
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                co_a++;
            }
            else if(s[i]=='b'){
                co_b++;
            }
            else{
                co_c++;
            }
        }
        //agar count k se kam hai then return -1 kro
        if(co_a < k || co_b < k ||co_c < k){
            return -1;
        }
        
        int i=0,j=0;
        int windowsize=INT_MIN;
        while(j<n){
            //agar ans  me se s[i] hta de win size increase hoga 
            if(s[j]=='a'){
                co_a--;
            }
            else if(s[j]=='b'){
                co_b--;
            }
            if(s[j]=='c'){
                co_c--;
            }

            //shrink
            while(i<=j && (co_a<k || co_b<k || co_c<k)){
                if(s[i]=='a'){
                    co_a++;
                }
                else if(s[i]=='b'){
                    co_b++;
                }
                else if(s[i]=='c'){
                    co_c++;
                }
                i++;
            }
            windowsize=max(windowsize,j-i+1);
            j++;
        }
        return n-windowsize;
    }
};