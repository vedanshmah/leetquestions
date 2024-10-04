class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2){
            return skill[0]*skill[1];
        }
        sort(skill.begin(),skill.end());
        
        int sum=skill[0]+skill[n-1];
        
        int st=0;
        int lt=n-1;
        long long int ans=0;
        while(st<lt){
            if(skill[st]+skill[lt]!=sum){
                return -1;
            }
            else{
                ans=ans+(skill[st]*skill[lt]);
                st++;
                lt--; 
            }
        }
        return ans;
    }
};