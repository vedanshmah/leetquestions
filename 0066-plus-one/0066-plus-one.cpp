class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int index=n-1;
        while(index>=0){
            if(digits[index]==9){
                digits[index]=0;
            }
            else{
                digits[index]=digits[index]+1;
                return digits;
            }
            index--;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};