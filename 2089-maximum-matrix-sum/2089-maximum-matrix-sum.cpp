class Solution {
public:
    long long int sumcalc(vector<vector<int>>& matrix,int n,int minno,int negcount){
        long long int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=ans+abs(matrix[i][j]);
            }
        }
        if(negcount%2!=0){
            ans=ans-minno-minno;
            return ans;
        }
        return ans;
        
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int negcount=0;
        int minno=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    negcount++;
                }
                minno=min(minno,abs(matrix[i][j]));
            }
        }
        return sumcalc(matrix,n,minno,negcount);
    }
};