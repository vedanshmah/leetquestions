class Solution {
public:
int nstaircase(int n,int*arr){
    //base
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[n]=1;
    }
    //check
    if(arr[n]!=-1){
        return arr[n];
    }
    //rec
    return arr[n]=nstaircase(n-1,arr)+nstaircase(n-2,arr);
}
    int climbStairs(int n) {
        int arr[n+1];
        for(int i=0;i<n+1;i++){
            arr[i]=-1;
        }
        return nstaircase(n,arr);
    }
};