class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstrowsum=0;
        for(int i=0;i<grid[0].size();i++){
            firstrowsum+=grid[0][i];
        }
        long long secondrowsum=0;
        long long res=LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            firstrowsum-=grid[0][i];
            long long robo2=max(firstrowsum,secondrowsum);
            res=min(robo2,res);
            secondrowsum+=grid[1][i];
        }
        return res;
    }
};