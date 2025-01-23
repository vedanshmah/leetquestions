class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rowco(m); // 1 2  
         vector<int> colco(n); //2 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowco[i]++;
                    colco[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(rowco[i]>1){
                        ans++;
                    }
                    else if(colco[j]>1){
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};