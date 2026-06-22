class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long int total_bulbs=ceil(brightness/3.0);
        sort(intervals.begin(),intervals.end());
        long long int curr_end=intervals[0][1];
        long long int total_time=intervals[0][1]-intervals[0][0]+1;
        for(int i=1;i<intervals.size();i++){
            if (curr_end >= intervals[i][0]) {
                if (intervals[i][1] > curr_end) {
                    total_time += intervals[i][1] - curr_end;
                    curr_end = intervals[i][1];
                }
            }else{
                total_time+=intervals[i][1]-intervals[i][0]+1;
                curr_end=intervals[i][1];
            }
        }
        return total_bulbs*total_time;
    }
};