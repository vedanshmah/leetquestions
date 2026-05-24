class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;

        for(char ch : password) {
            st.insert(ch);
        }

        int points = 0;

        for(char ch : st) {
            if(ch >= 'a' && ch <= 'z') {
                points += 1;
            }
            else if(ch >= 'A' && ch <= 'Z') {
                points += 2;
            }
            else if(ch >= '0' && ch <= '9') {
                points += 3;
            }
            else if(ch == '!' || ch == '@' || ch == '#' || ch == '$') {
                points += 5;
            }
        }

        return points;
    }
};