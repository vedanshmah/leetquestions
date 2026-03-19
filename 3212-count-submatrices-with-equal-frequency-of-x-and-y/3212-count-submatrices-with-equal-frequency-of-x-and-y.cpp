class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> colSum(m, 0);
        vector<int> colX(m, 0);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    colSum[j] += 1;
                    colX[j] += 1;
                }
                else if(grid[i][j] == 'Y') {
                    colSum[j] -= 1;
                }
            }
            
            int sum = 0, countX = 0;
            
            for(int j = 0; j < m; j++) {
                sum += colSum[j];
                countX += colX[j];
                
                if(sum == 0 && countX > 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};