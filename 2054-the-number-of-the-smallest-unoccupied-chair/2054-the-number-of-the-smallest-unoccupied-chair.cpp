class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int> chair(n,-1);
        int targetarrival=times[targetFriend][0];
        sort(begin(times),end(times));

        for(int i=0;i<n;i++){
            int arrival=times[i][0];
            int depart=times[i][1];
            for(int i=0;i<n;i++){
                if(chair[i]<=arrival){
                    chair[i]=depart;
                    if(arrival==targetarrival){
                        return i;
                    }
                    break;
                }
                
            }

        }
        return -1;
    }
};