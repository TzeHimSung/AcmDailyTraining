class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        using ll = long long;
        return (((ll)rec2[0] - rec1[2]) * ((ll)rec2[2] - rec1[0]) < 0) && (((ll)rec2[1] - rec1[3]) * ((ll)rec2[3] - rec1[1]) < 0);
    }
};