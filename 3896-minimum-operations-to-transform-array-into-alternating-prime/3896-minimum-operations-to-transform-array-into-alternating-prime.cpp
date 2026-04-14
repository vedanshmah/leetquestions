class Solution {
public:
    const int MAXN = 200000;
    vector<bool> isPrime;

    void buildSieve() {
        isPrime.assign(MAXN + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MAXN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAXN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        buildSieve();

        long long ops = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (i % 2 == 0) {
                while (!isPrime[x]) {
                    x++;
                    ops++;
                }
            } else {
                while (isPrime[x]) {
                    x++;
                    ops++;
                }
            }
        }

        return ops;
    }
};