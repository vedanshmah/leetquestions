class Solution {
public:
    bool isCircularSentence(string sen) {
        int n=sen.length();
        if(sen[0]!=sen[n-1]){
            return false;
        }
        for(int i=0;i<n;i++){
            if(sen[i]==' ' && sen[i-1]!=sen[i+1]){
                //if(sen[i-1]!=sen[i+1]){
                    return false;
                //}
            }
        }
        return true;
    }
};