class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int res=0;
        for(int st_col=0;st_col<cols;st_col++){
            for(int j=st_col;j<cols;j++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int cumsum=0;
                for(int i=0;i<rows;i++){
                    cumsum+=matrix[i][j];
                    if(st_col>0){
                        cumsum-=matrix[i][st_col-1];
                    }
                    if(mp.count(cumsum-target)){
                        res+=mp[cumsum-target];
                    }
                    mp[cumsum]++;
                }
            }
        }
        return res;
    }
};