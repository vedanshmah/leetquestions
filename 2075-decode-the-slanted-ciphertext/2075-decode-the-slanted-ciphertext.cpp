class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size() / rows;
        string ans="";
        for(int j=0;j<cols;j++){
            int i=0;
            int tempj=j;
            while(i<rows && tempj<cols){
                int idx = (i*cols) + tempj;
                ans.push_back(encodedText[idx]);
                i++;
                tempj++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};