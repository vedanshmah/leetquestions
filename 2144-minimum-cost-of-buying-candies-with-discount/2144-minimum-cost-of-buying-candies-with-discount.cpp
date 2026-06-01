class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int co=0;
        int ans=0;
        for(int i=cost.size()-1;i>=0;i--){
            if(co<2){
                ans+=cost[i];
                co++;
            }
            if(co>=2){
                co=0;
                i-=1;
            }
        }
        return ans;
    }
};