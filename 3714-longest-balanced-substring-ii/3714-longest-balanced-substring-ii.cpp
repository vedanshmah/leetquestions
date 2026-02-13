class Solution {
public:
    int helper(string&s,int ch1,int ch2){
        unordered_map<int,int> mp;
        int maxl=0;
        int n=s.size();
        int count_ch1=0;
        int count_ch2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=ch1 && s[i]!=ch2){
                mp.clear();
                count_ch1=0;
                count_ch2=0;
                continue;
            }
            if(s[i]==ch1){
                count_ch1++;
            }
            if(s[i]==ch2){
                count_ch2++;
            }
            if(count_ch1==count_ch2){
                maxl=max(maxl,count_ch1+count_ch2);
            }
            int diff=count_ch1-count_ch2;
            if(mp.count(diff)){
                maxl=max(maxl,i - mp[diff]);
            }else{
                mp[diff]=i;
            }
        }
        return maxl;

    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxl=0;
        //case1
        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
            count++;
            }
            else{
                maxl=max(maxl,count);
                count=1;
            }
        }
        maxl=max(maxl,count);

        //case2
        maxl=max(maxl,helper(s,'a','b'));
        maxl=max(maxl,helper(s,'b','c'));
        maxl=max(maxl,helper(s,'a','c'));

        //case3
        int coa=0;
        int cob=0;
        int coc=0;
        map<pair<int,int>,int> mp;
        mp[{0,0}] = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                coa++;
            }
            if(s[i]=='b'){
                cob++;
            }
            if(s[i]=='c'){
                coc++;
            }
            if(coa==cob && coa==coc){
                maxl=max(maxl,coa*3);
            }
            int diffab=coa-cob;
            int diffac=coa-coc;
            if(mp.count({diffab,diffac})){
                maxl=max(maxl,i - mp[{diffab,diffac}]);
            }else{
                mp[{diffab,diffac}]=i;
            }
        }
        return maxl;
    }
};