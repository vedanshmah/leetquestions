class Solution {
public:
    int M=1e9+7;
    int m,n;
    typedef long long ll;
    vector<vector<pair<ll,ll>>> dp;
    pair<ll,ll> helper(int i,int j,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }

        ll maxval=LLONG_MIN;
        ll minval=LLONG_MAX;
        if(dp[i][j] != make_pair(LLONG_MIN,LLONG_MAX)){
            return dp[i][j];
        }
        if(i+1<m){
            auto [downmax,downmin]=helper(i+1,j,grid);
            maxval=max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
            minval=min({minval,grid[i][j]*downmin,grid[i][j]*downmax});
        }
        if(j+1<n){
            auto [rmax,rmin]=helper(i,j+1,grid);
            maxval=max({maxval,grid[i][j]*rmax,grid[i][j]*rmin});
            minval=min({minval,grid[i][j]*rmax,grid[i][j]*rmin});
        }


        return dp[i][j]={maxval,minval};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        auto [maxpro,minpro]=helper(0,0,grid);
        return (maxpro>=0)?maxpro%M:-1;
    }
};