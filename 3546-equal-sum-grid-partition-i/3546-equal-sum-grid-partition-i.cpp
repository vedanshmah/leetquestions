class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        
        vector<long long> rowsum(rows);
        vector<long long> prerowsum(rows);

        for(int i = 0; i < rows; i++){
            rowsum[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        prerowsum[0] = rowsum[0];
        for(int i = 1; i < rows; i++){
            prerowsum[i] = prerowsum[i-1] + rowsum[i];
        }

      
        vector<long long> colsum(cols, 0);
        vector<long long> precolsum(cols);

        for(int j = 0; j < cols; j++){
            for(int i = 0; i < rows; i++){
                colsum[j] += grid[i][j];
            }
        }

        precolsum[0] = colsum[0];
        for(int j = 1; j < cols; j++){
            precolsum[j] = precolsum[j-1] + colsum[j];
        }

        long long total = prerowsum[rows - 1];

    
        for(int i = 0; i < rows - 1; i++){
            if(prerowsum[i] == total - prerowsum[i])
                return true;
        }

        for(int j = 0; j < cols - 1; j++){
            if(precolsum[j] == total - precolsum[j])
                return true;
        }

        return false;
    }
};