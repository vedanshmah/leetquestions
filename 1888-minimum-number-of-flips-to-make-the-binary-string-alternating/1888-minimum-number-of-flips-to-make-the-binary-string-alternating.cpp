class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;

        int e1 = 0, e2 = 0;
        int mine = INT_MAX;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {

            char p1 = (right % 2) ? '1' : '0';
            char p2 = (right % 2) ? '0' : '1';

            if (s[right] != p1) e1++;
            if (s[right] != p2) e2++;

            if (right - left + 1 > n) {
                char lp1 = (left % 2) ? '1' : '0';
                char lp2 = (left % 2) ? '0' : '1';

                if (s[left] != lp1) e1--;
                if (s[left] != lp2) e2--;

                left++;
            }

            if (right - left + 1 == n) {
                mine = min(mine, min(e1, e2));
            }
        }

        return mine;
    }
};