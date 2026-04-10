class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> vec(10,1);
        for(int i=1;i<10;i++){
            vec[i]=vec[i-1]*i;
        }
        vector<int> digcount(10,0);
        int temp=n;
        int sum=0;
        while(temp){
            int rem=temp%10;
            digcount[rem]++;
            sum+=vec[rem];
            temp/=10;
        }
        int co1=to_string(n).length();
        int co2=to_string(sum).length();
        if(co1!=co2){
            return false;
        }
        vector<int> sumcount(10,0);
        temp=sum;
        while(temp){
            int rem=temp%10;
            sumcount[rem]++;
            temp/=10;
        }
        for(int i=0;i<10;i++){
            if(digcount[i]!=sumcount[i]){
                return false;
            }
        }
        return true;
    }
};