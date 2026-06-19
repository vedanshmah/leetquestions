class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0;
        int curralt=0;
        for(int i=0;i<gain.size();i++){
            curralt+=gain[i];
            res=max(res,curralt);
        }
        return res;
    }
};