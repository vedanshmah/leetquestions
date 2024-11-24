class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long int sum=0;
        int negcount=0;
        int minno=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    negcount++;
                }
                minno=min(minno,abs(matrix[i][j]));
            }
        }
        //negative no:
        //  even= tab toh direct sum nikalo abs lgake
        //  odd= isme sbka sum nikalke min no se minus krdo(2 baar kyonki 
        //          sum ke time voh ek baar add hua tha)
        if(negcount%2!=0){
            return sum-2*minno;
        }
        return sum;
    }
};