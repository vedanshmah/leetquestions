class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto point:points){
            double dist=((point[0]*point[0])+(point[1]*point[1]));
            pq.push({dist,{point[0],point[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        for (int i = 0; i < k; ++i) {
            auto top=pq.top();
            pq.pop();
            res.push_back({top.second.first,top.second.second});
        }
        return res;
    }
};