class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finish1=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int landtime=landStartTime[i]+landDuration[i];
                int waterstart=max(landtime,waterStartTime[j]);
                finish1=min(finish1,waterstart+waterDuration[j]);
            }
        }
        int finish2=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            for(int j=0;j<landStartTime.size();j++){
                int watertime=waterStartTime[i]+waterDuration[i];
                int landstart=max(watertime,landStartTime[j]);
                finish2=min(finish2,landstart+landDuration[j]);
            }
        }
        return min(finish1,finish2);
    }
};