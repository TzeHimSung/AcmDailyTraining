class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxx = 0;
        vector<int>maxPrice(prices.size(), 0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            maxPrice[i] = maxx;
            maxx = max(maxx, prices[i]);
        }
        maxx = 0;
        for (int i = 0; i < prices.size(); i++) {
            maxx = max(maxx, maxPrice[i] - prices[i]);
        }
        return maxx;
    }
};
