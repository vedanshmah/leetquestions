class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int size=(n*n)+1;
        vector<int> temp(size, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int idx=grid[i][j];
                temp[idx]++;
            }
        }
        int a,b;
        for(int i=1;i<size;i++){
            if(temp[i]==2){
                a=i;
            }
            if(temp[i]==0){
                b=i;
            }
        }
        return {a,b};
    }
};