class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int n=arr1.size(),m=arr2.size();
        for(int i=0;i<n;i++){
            mp1[arr1[i]]++;
        }
        for(int i=0;i<m;i++){
            mp2[arr2[i]]++;
        }

        vector<int> res(n,0);
        int idx=0;
        for(int i=0;i<m;i++){
            if(mp1[arr2[i]]>0){
                for(int j=1;j<=mp1[arr2[i]];j++){
                    res[idx]=arr2[i];
                    idx++;
                }
            }
        }
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(mp2.find(arr1[i])==mp2.end()){
                temp.push_back(arr1[i]);
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            res[idx]=temp[i];
            idx++;
        }
        return res;
    }
};