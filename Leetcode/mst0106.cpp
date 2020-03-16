// class Solution {
// public:
//     string compressString(string S) {
//         vector<pair<char, int>>vec;
//         int cnt = 1;
//         for (int i = 1; i < S.size(); i++) {
//             if (S[i] == S[i - 1]) cnt++;
//             else {
//                 vec.push_back(make_pair(S[i - 1], cnt));
//                 cnt = 1;
//             }
//         }
//         vec.push_back(make_pair(S[S.size() - 1], cnt));
//         string ret = "";

//         function<string(int)> convert = [&](int num)->string{
//             string ret = "";
//             while (num) {
//                 ret += (char)(num % 10 + '0');
//                 num /= 10;
//             }
//             reverse(ret.begin(), ret.end());
//             return ret;
//         };

//         for (auto par : vec) {
//             ret += par.first + convert(par.second);
//         }
//         return ret.size() < S.size() ? ret : S;
//     }
// };

class Solution {
public:
    string compressString(string S) {
        string ret = "";
        int cnt = 1;
        for (int i = 0; i < S.size(); i++) {
            if (i != S.size() - 1 && S[i] == S[i + 1]) {
                cnt++; continue;
            }
            ret.push_back(S[i]);
            ret.append(to_string(cnt));
            cnt = 1;
        }
        return ret.size() < S.size() ? ret : S;
    }
};