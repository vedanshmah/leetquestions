class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstrowsum=0;//first row ka tsum
        for(int i=0;i<grid[0].size();i++){
            firstrowsum+=grid[0][i];
        }
        long long secondrowsum=0; //2nd row ka sum-->for robo 2 agr col change hota hai toh we need sum of 2nd row upto uss col tak jaha pe change hua
        long long res=LONG_LONG_MAX; /// isme final ans ayega robo2 ke points
        for(int i=0;i<grid[0].size();i++){
            firstrowsum-=grid[0][i];  //i=jis col se change hoga path-> agr 0 se hoga toh robo 2 ke liye 0,0 pe 0 point honge toh first row ke tsum se grid[0][i] minus krdo
            long long robo2=max(firstrowsum,secondrowsum); //robo 2 ke points agr col = i pe change hota hai
            res=min(robo2,res); //final ans
            secondrowsum+=grid[1][i]; //storage for second row for comaprison at robo2(line 12)
        }
        return res;
    }
};