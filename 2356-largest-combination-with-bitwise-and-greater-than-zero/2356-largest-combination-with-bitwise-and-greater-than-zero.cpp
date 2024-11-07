class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        int maxgrpsize=0;
        for(int i=0;i<24;i++){
            int co=0;
            for(int j=0;j<n;j++){
                if((candidates[j] & (1<<i)) != 0){
                    co++;
                }
            }
            maxgrpsize=max(co,maxgrpsize);
        }
        return maxgrpsize;
    }
};