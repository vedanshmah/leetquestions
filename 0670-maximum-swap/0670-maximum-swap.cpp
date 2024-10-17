class Solution {
public:
    int maximumSwap(int num) {
        string s1=to_string(num);
        int n1=s1.length();
        vector<int> maxi(n1);
        maxi[n1-1]=n1-1;
        for(int i=n1-2;i>=0;i--){
            if(s1[i]>s1[maxi[i+1]]){
                maxi[i]=i;
            }
            else{
                maxi[i]=maxi[i+1];
            }
        }
        for(int i=0;i<n1;i++){
            if(s1[i]<s1[maxi[i]]){
                swap(s1[i],s1[maxi[i]]);
                break;
            }
        }
        return stoi(s1);
    }
};