class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int times=k/2;
        int row=x,col=y;
        int temp=k;
        // row=2 col =1 k=3
        for(int co=0;co<times;co++){

            int bottom=x+k-1-co;
            for(int i=col;i<col+k;i++){
                swap(grid[row][i],grid[bottom][i]);
            }
            
            row++;
        }
        return grid;
    }
};