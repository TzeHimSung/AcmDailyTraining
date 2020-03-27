class Solution {
public:
    bool hasGroupsSizeX(vector<int> &deck) {
        map<int, int>cnt;
        for (auto i : deck) cnt[i]++;
        int maxNum = 0;
        for (auto i : cnt) maxNum = max(maxNum, i.second);
        for (int i = 2; i <= maxNum; i++) {
            int flag = true;
            for (auto j : cnt) {
                if (j.second < i || j.second % i) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
