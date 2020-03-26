class Solution {
public:
    int myAtoi(string str) {
        int i = 0, bol = 1;
        long long res = 0;
        while (i < str.size() && str[i] == ' ') i++;
        if (i == str.size()) return 0;
        if (str[i] == '-') {
            bol = -1;
            i++;
        } else if (str[i] == '+') {
            bol = 1;
            i++;
        }
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + str[i++] - '0';
            if (res >= 2147483648) {
                if (bol == 1) return INT_MAX;
                else return INT_MIN;
            }
        }
        return res * bol;
    }
};
