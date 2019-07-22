/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
struct Car {
    int length, speed;
    double pos;
    Car() {}
    Car(int a, double b, int c): length(a), pos(b), speed(c) {}
    bool operator<(const Car &rhs)const {
        return pos > rhs.pos;
    }
};
int l[maxn], s[maxn], v[maxn];
Car car[maxn];
set<int>poped;
priority_queue<pair<double, pair<int, int>>> deltaTime;

void init() {
    poped.clear();
    while (!deltaTime.empty()) deltaTime.pop();
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        init();
        rep1(i, 0, n) scanf("%d", &l[i]);
        rep1(i, 0, n) scanf("%d", &s[i]);
        rep1(i, 0, n) scanf("%d", &v[i]);

        rep1(i, 0, n) car[i] = Car(l[i], (double)s[i], v[i]);
        sort(car, car + 1 + n);
        Car me = car[0]; int slowCarPos = n;
        for (int i = n; i >= 0; i--) {
            if (car[i].speed >= me.speed) continue;
            else {
                slowCarPos = i;
                break;
            }
        }
        if (slowCarPos == n) {
            printf("%.6f\n", (double)car[0].pos / (double)car[0].speed);
            continue;
        }
        rep0(i, 0, slowCarPos) {
            double tmpTime = (double)(car[i].speed - car[i + 1].speed) / (double)(car[i].pos - car[i + 1].pos - car[i + 1].length);
            if (tmpTime > eps)
                deltaTime.push(mp(tmpTime, mp(i, i + 1)));
        }
        double ans = 0;
        double currTime = 0.0, natureTime = (double)me.pos / (double)me.speed;
        while (!deltaTime.empty() && (int)deltaTime.size() != 1) {
            auto currInv = deltaTime.top();
            deltaTime.pop();
            if (poped.count(currInv.second.first) || poped.count(currInv.second.second)) continue;
            if (!currInv.second.first) {
                double crashTime = (double)(car[currInv.second.first].pos - car[currInv.second.second].pos - car[currInv.second.second].length)
                                   / (double)currInv.first;
                ans += crashTime;
                car[currInv.second.first].length += car[currInv.second.second].length;
                car[currInv.second.first].pos -= car[currInv.second.second].length + crashTime * car[currInv.second.first].speed;
                car[currInv.second.first].speed = car[currInv.second.second].speed;
                poped.insert(currInv.second.second);
                deltaTime.push(mp((double)(car[currInv.second.first].pos - car[currInv.second.second + 1].pos)
                                  / (double)(car[currInv.second.first].speed - car[currInv.second.second + 1].speed), mp(currInv.second.first, currInv.second.second + 1)));
            } else {
                double crashTime = (double)(car[currInv.second.first].pos - car[currInv.second.second].pos - car[currInv.second.second].length)
                                   / (double)currInv.first;
                if (currTime - natureTime >= -eps) {
                    printf("%.6f\n", natureTime);
                    goto mark;
                } else {
                    ans += crashTime;
                    car[currInv.second.first].length += car[currInv.second.second].length;
                    car[currInv.second.first].pos -= car[currInv.second.second].length + crashTime * car[currInv.second.first].speed;
                    car[currInv.second.first].speed = car[currInv.second.second].speed;
                    poped.insert(currInv.second.second);
                    deltaTime.push(mp((double)(car[currInv.second.first].pos - car[currInv.second.second + 1].pos)
                                      / (double)(car[currInv.second.first].speed - car[currInv.second.second + 1].speed), mp(currInv.second.first, currInv.second.second + 1)));

                }
            }
        }
        printf("%.6f\n", ans);
mark:;
    }
    return 0;
}
