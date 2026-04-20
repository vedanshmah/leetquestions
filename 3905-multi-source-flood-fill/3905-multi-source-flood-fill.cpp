class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> timereached(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        int currenttime=0;
        for(auto &src:sources){
            int r=src[0];
            int c=src[1];
            int col=src[2];
            grid[r][c]=col;
            timereached[r][c]=0;
            q.push({r,c});
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            currenttime++;
            int batchsize=q.size();
            for(int i=0;i<batchsize;i++){
                auto [r, c] = q.front();
                q.pop();
                int currcolor=grid[r][c];
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = currcolor;
                            timereached[nr][nc] = currenttime;
                            q.push({nr, nc});
                        } 
                        else if (timereached[nr][nc] == currenttime) {
                            grid[nr][nc] = max(grid[nr][nc], currcolor);
                        }
                    }
                }
            }
        }
        return grid;
    }
};