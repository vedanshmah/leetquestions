class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int rows = grid.size();
        int swaps = 0;

        // Step 1
        vector<int> vec(rows, 0);
        for(int a = 0; a < rows; a++) {
            for(int b = rows - 1; b >= 0; b--) {
                if(grid[a][b] == 0)
                    vec[a]++;
                else
                    break;
            }
        }

        // Step 2
        for(int i = 0; i < rows; i++) {
            int required = rows - i - 1;

            int j = i;
            while(j < rows && vec[j] < required) {
                j++;
            }

            if(j == rows) {
                return -1;
            }

            swaps += j - i;

            while(j > i) {
                swap(vec[j], vec[j - 1]);
                j--;
            }
        }

        return swaps;
    }
};