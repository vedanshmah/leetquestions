class Solution {
public:
    int M = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n));

        int N = m * n;
        vector<int> leftpro(N), rightpro(N);

        leftpro[0] = 1;
        rightpro[N - 1] = 1;

       
        for (int i = 1; i < N; i++) {
            int val = grid[(i - 1) / n][(i - 1) % n];   
            leftpro[i] = (1LL * leftpro[i - 1] * val) % M; 
        }
        for (int i = N - 2; i >= 0; i--) {
            int val = grid[(i + 1) / n][(i + 1) % n];   
            rightpro[i] = (1LL * rightpro[i + 1] * val) % M;  
        }
        for (int i = 0; i < N; i++) {
            int x = i / n;  
            int y = i % n;
            p[x][y] = (1LL * leftpro[i] * rightpro[i]) % M;  
        }

        return p;
    }
};