class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        function<void(string, int, int)> solve = [&](string s, int l, int r) {
            if (l > n || r > n || l < r) return;
            if (l == n && r == n) {
                ans.push_back(s);
                return;
            }
            solve(s + '(', l + 1, r);
            solve(s + ')', l, r + 1);
        };

        solve("", 0, 0);

        return ans;
    }
};