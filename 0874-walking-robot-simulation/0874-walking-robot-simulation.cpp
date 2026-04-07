class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dir = {
            {0,1},   // North 0
            {1,0},   // East 1
            {0,-1},  // South 2
            {-1,0}   // West 3
        };
        int d=0;
        unordered_set<string> st;
        for (auto &obs : obstacles) {
            string key = to_string(obs[0]) + "," + to_string(obs[1]);
            st.insert(key);
        }
        int x=0,y=0;
        int maxDist = 0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                d=(d+1)%4;
            }else if(commands[i]==-2){
                d=(d+3)%4;
            }else{
                for(int step = 0; step < commands[i]; step++){
                    int nx=x+dir[d].first;
                    int ny=y+dir[d].second;
                    string next=to_string(nx) + "," + to_string(ny);
                    if(st.count(next)){
                        break;
                    }
                    x=nx;
                    y=ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};