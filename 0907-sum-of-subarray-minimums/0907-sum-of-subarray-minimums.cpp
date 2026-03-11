class Solution {
public:
    int M= 1e9+7;
    vector<int> NSL(vector<int>& arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;
            }else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                res[i]=st.empty() ? -1:st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> NSR(vector<int>& arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
            }else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                res[i]=st.empty() ? n:st.top();
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsr=NSR(arr,n);
        vector<int> nsl=NSL(arr,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            int sl=i-nsl[i];
            int sr=nsr[i]-i;
            long long totalways=sl*sr;
            long long totalsum=arr[i]*totalways;
            sum=(sum+totalsum)%M;
        }
        return sum;
    }
};