class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans(seq.size(), 0);
        int id = 0;
        for (auto ch : seq) {
            ans[id++] = ch == '(' ? (id & 1) : ((id + 1) & 1);
        }
        return ans;
    }
};
