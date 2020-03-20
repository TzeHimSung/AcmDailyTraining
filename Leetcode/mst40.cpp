class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int>ret;
        for (int i = 0; i < min((int)arr.size(), k); i++) ret.push_back(arr[i]);
        return ret;
    }
};