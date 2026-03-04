class Solution {
public:
    bool check(vector<vector<int>>& mat,int row,int col){
        for(int i=0;i<mat[row].size();i++){
            if(mat[row][i]==1 && i!=col){
                return false;
            }
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]==1 && i!=row){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int rows=mat.size();
        int ans=0;
        int cols=mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1 && check(mat,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};