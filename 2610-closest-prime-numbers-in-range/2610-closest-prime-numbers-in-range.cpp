class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=right;
        vector<bool> primeornot(n+1,true);
        primeornot[0]=primeornot[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primeornot[i]){
                for(int j=i*i;j<=n;j+=i){
                    primeornot[j]=false;
                }
            }
        }
        vector<int> primes;
        int co=0;
        for(int i=left;i<=right;i++){
            if(primeornot[i]){
                primes.push_back(i);
            }
        }
        int min=INT_MAX;
        vector<int> result = {-1, -1};
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < min) {
                min = diff;
                result = {primes[i - 1], primes[i]};
            }
        }
        return result;
    }
};