class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<vector<int>> direction={{0,-1},{0,1},{-1,0},{1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<PP,vector<PP>,greater<>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        //edges ko add kro
        //top bottom buildings
        for(int col=0;col<m;col++){
            for(int row:{0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }
        //left right buildings
        for(int row=0;row<n;row++){
            for(int col:{0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        int water=0;
        while(!pq.empty()){
            PP p=pq.top();
            pq.pop();

            int height=p.first;
            int i=p.second.first;
            int j=p.second.second;
            for(vector<int>& dir:direction){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m && !visited[i_][j_]){
                    water+=max(height-heightMap[i_][j_],0);

                    pq.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_]=true;
                } 
            }
        }
        return water;
    }
};