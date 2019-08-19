/* Codeforces Contest 2019_mutc_09
 * Problem E
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
        int T;
        cin >> T;
        while (T--) {
                string str;
                cin >> str;
                int i = 0;
                for (auto ch: str) {
                        if (ch == 'y') {
                                i++;
                        } else {
                                break;
                        }
                }
                if (i < str.length() && str[i] == 'z') {
                        str[i] = 'b';
                }
                cout << str << endl;
        }
        return 0;
}
