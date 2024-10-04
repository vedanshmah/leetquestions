class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        if(n==2){
            return skill[0]*skill[1];
        }
        sort(skill.begin(),skill.end());
        int sum=skill[0]+skill[n-1];
        vector<vector<int>> z(n/2,vector<int>(2));
        z[0][0]=skill[0];
        z[0][1]=skill[n-1];
        int st=1;
        int lt=n-2;
        while(st<lt){
            if(skill[st]+skill[lt]!=sum){
                return -1;
            }
            else{
                z[st][0]=skill[st];
                z[st][1]=skill[lt];
                st++;
                lt--; 
            }
        }
        long long int ans=0;
        for(int i=0;i<n/2;i++){
            ans=ans+(z[i][0]*z[i][1]);
        }
        return ans;
    }
};