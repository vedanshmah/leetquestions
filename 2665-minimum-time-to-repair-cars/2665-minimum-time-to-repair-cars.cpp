class Solution {
public:
    bool solve(vector<int>& ranks,int cars,long long int time){
        long long co=0;
        for(int i=0;i<ranks.size();i++){
            co+=sqrt((time*1.0)/ranks[i]);
        }
        if(co>=cars){
            return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long int maxrank=LLONG_MIN;
        for(int i=0;i<ranks.size();i++){
            maxrank=max(maxrank,(long long)ranks[i]);
        }
        long long int h=maxrank*cars*cars;
        long long int l=1;
        long long ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(solve(ranks,cars,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};