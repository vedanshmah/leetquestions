class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int pt1=0,n1=nums1.size();
        int pt2=0,n2=nums2.size();
        while(pt1<n1 && pt2<n2){
            if(nums1[pt1][0]==nums2[pt2][0]){
                res.push_back({nums1[pt1][0],nums1[pt1][1]+nums2[pt2][1]});
                pt1++;
                pt2++;
            }
            else if(nums1[pt1][0]>nums2[pt2][0]){
                res.push_back({nums2[pt2][0],nums2[pt2][1]});
                pt2++;
            }
            else{
                res.push_back({nums1[pt1][0],nums1[pt1][1]});
                pt1++;
            }
        }
        while(pt1<n1){
            res.push_back({nums1[pt1][0],nums1[pt1][1]});
            pt1++;
        }

        while(pt2<n2){
            res.push_back({nums2[pt2][0],nums2[pt2][1]});
            pt2++;
        }
        return res;
    }
};