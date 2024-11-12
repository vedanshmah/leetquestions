class Solution {
public:
    int getmaxbeauty(int key,vector<vector<int>>& items,int n){
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        int maxbeauty=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(items[mid][0]>key){
                e=mid-1;
                
            }
            else if(items[mid][0]<=key){
                maxbeauty=max(maxbeauty,items[mid][1]);
                s=mid+1;
               
            }
        }
        return maxbeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        sort(items.begin(),items.end());
        int maxb=items[0][1];
        for(int i=1;i<n;i++){
            maxb=max(maxb,items[i][1]);
            items[i][1]=maxb;
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            int t=getmaxbeauty(queries[i],items,n);
            res.push_back(t);
        }
        return res;
    }
};