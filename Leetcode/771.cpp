class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char>s;
        int ans = 0;
        for (auto i : J) s.insert(i);
        for (auto i : S) {
            if (s.count(i)) ans++;
        }
        return ans;
    }
};
