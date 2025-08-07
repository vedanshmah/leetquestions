    class Solution {
        using ll = long long;
    public:
        long long numOfSubsequences(string s) {

            int n=s.size();
            vector<int> lco(s.size(),0);
            vector<int> tco(s.size(),0);
            
            //counting l at left and t at right at each index
            if(s[0]=='L'){
                lco[0]++;
            }
            for(int i=1;i<n;i++){
                if(s[i]=='L'){
                    lco[i]=1+lco[i-1];
                }
                else{
                    lco[i]=lco[i-1];
                }
            }
            if(s[n-1]=='T'){
                tco[n-1]++;
                
            }
            for(int i=n-2;i>=0;i--){
                if(s[i]=='T'){
                    tco[i]=1+tco[i+1];
                    
                }
                else{
                    tco[i]=tco[i+1];
                }
            }
            int cco=0;
            for(int i=0;i<n;i++){
                if(s[i]=='C'){
                    cco++;
                }
            }
            long long int subseqbefore=0;
            for(int i=1;i<n-1;i++){
                if(s[i]=='C'){
                    subseqbefore=subseqbefore+(lco[i-1]*tco[i+1]);
                }
            }
            long long int gain=0;
            for(int i=0;i<n;i++){
                ll x=lco[i];
                ll y=tco[i];
                gain=max(gain,x*y);
            }
            long long int subseqbyc=subseqbefore+gain;

            long long int subseqbyl=0;
            for(int i=0;i<n;i++){
                ll x=lco[i];
                ll y=tco[i];
                if(s[i]=='C'){
                    subseqbyl+=(x+1)*y;
                }
            }

            long long int subseqbyt=0;
            for(int i=0;i<n;i++){
                ll x=lco[i];
                ll y=tco[i];
                if(s[i]=='C'){
                    subseqbyt+=x*(y+1);
                }
            }

            long long int ans=max(subseqbyc,max(subseqbyl,subseqbyt));
            return ans;
        }
    };