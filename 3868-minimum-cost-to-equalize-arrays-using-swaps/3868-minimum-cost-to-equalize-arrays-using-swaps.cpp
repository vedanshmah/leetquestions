class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(80001, 0);
        vector<int> freq2(80001, 0);
        for(int i=0;i<nums1.size();i++){
            freq1[ nums1[i] ]++;
            freq2[ nums2[i] ]++;
        }
        for(int i=0;i<freq1.size();i++){
            if((freq1[i]+freq2[i]) %2 != 0){
                return -1;
            }
        }
        int swaps=0;
        for(int i=0;i<freq1.size();i++){
            int diff=freq1[i]-freq2[i];
            if(diff>0){
                swaps+=diff/2;
            }
        }
        return swaps;
    }
};