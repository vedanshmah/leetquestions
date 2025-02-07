class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colco;
        unordered_map<int,int> ballcol;
        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];

            if(ballcol.find(ball)!=ballcol.end()){
                int prevcol=ballcol[ball];
                colco[prevcol]--;
                if(colco[prevcol]==0){
                    colco.erase(prevcol);
                }
            }
            ballcol[ball]=color;

            colco[color]++;
            res[i]=colco.size();
        }
        return res;
    }
};