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
/* namespace */
using namespace std;
/* header end */

int n, c;

struct Fraction {
    ll fz, fm, negative = 0;
    Fraction() {
        fz = 0, fm = 1;
        negative = 0;
    }
    Fraction(ll a, ll b) {
        fz = a, fm = b;
        negative = a < 0 ? -1 : 1;
    }
    Fraction operator+(const Fraction &rhs) {
        Fraction ret, tmpA = *this, tmpB = rhs;
        tmpA.fz *= tmpB.fm, tmpB.fz *= tmpA.fm;
        ret.fm = tmpA.fm * tmpB.fm;
        ret.fz = tmpA.fz * tmpA.negative + tmpB.fz * tmpB.negative;
        ll gcd = __gcd(ret.fz, ret.fm);
        ret.fz /= gcd, ret.fm /= gcd;
        if (ret.fz < 0) ret.negative = -1; else ret.negative = 1;
        return ret;
    }
    Fraction operator-(const Fraction &rhs) {
        Fraction ret, tmpA = *this, tmpB = rhs;
        tmpA.fz *= tmpB.fm, tmpB.fz *= tmpA.fm;
        ret.fm = tmpA.fm * tmpB.fm;
        ret.fz = tmpA.fz * tmpA.negative - tmpB.fz * tmpB.negative;
        ll gcd = __gcd(ret.fz, ret.fm);
        ret.fz /= gcd, ret.fm /= gcd;
        if (ret.fz < 0) ret.negative = -1; else ret.negative = 1;
        return ret;
    }
    Fraction operator*(const Fraction &rhs) {
        Fraction ret, tmpA = *this, tmpB = rhs;
        ret.fz = tmpA.fz * tmpA.negative * tmpB.fz * tmpB.negative;
        ret.fm = tmpA.fm * tmpB.fm;
        ll gcd = __gcd(ret.fz, ret.fm);
        ret.fz /= gcd, ret.fm /= gcd;
        ret.negative = tmpA.negative * tmpB.negative;
        return ret;
    }
    Fraction operator/(const Fraction &rhs) {
        Fraction ret, tmpA = *this, tmpB = rhs;
        swap(tmpB.fz, tmpB.fm);
        ret = tmpA * tmpB;
        return ret;
    }
    Fraction operator+(const int rhs) {
        Fraction ret = *this, tmp = Fraction((int)rhs, 1);
        ret = ret + tmp;
        return ret;
    }
    Fraction operator*(const int rhs) {
        Fraction ret = *this;
        ret.fz *= rhs;
        ll gcd = __gcd(ret.fz, ret.fm);
        ret.fz /= gcd, ret.fm /= gcd;
        return ret;
    }
    Fraction operator/(const int rhs) {
        Fraction ret = *this;
        ret = ret / Fraction(rhs, 1);
        return ret;
    }
    bool operator<(const Fraction &rhs) const {
        ll left = this->fz * this->negative * rhs.fm;
        ll right = rhs.fz * rhs.negative * this->fm;
        return left < right;
    }
    bool operator==(const Fraction &rhs) const {
        return ((this->fz == rhs.fz) && (this->fm == rhs.fm) && (this->negative == rhs.negative));
    }
    bool operator<=(const Fraction &rhs) const {
        return (*this < rhs || *this == rhs);
    }
};

struct Function {
    int a, b;
    Fraction zeroPoint;
    Function() {
        a = 0, b = 1;
    }
    Function(int a, int b) {
        a = a, b = b;
        zeroPoint = Fraction(-b, 1) / Fraction(a, 1);
    }
    bool operator<(const Function &rhs)const {
        return zeroPoint < rhs.zeroPoint;
    }
    bool operator==(const Function &rhs)const {
        return (a == rhs.a && b == rhs.b);
    }
    Fraction getValue(Fraction x) {
        return x * a + b;
    }
};

int solve(vector<Function> &func, Fraction lf, Fraction rf, Fraction &solution) {
    int currA = 0, currB = 0;
    for (auto i : func) {
        if (lf <= i.zeroPoint) currA += -i.a, currB -= i.b;
        else currA += i.a, currB += i.b;
    }
    Fraction result = Fraction(c - currB, currA);
    if (lf <= result && result <= rf) {
        solution.fm = result.fm, solution.fz = result.fz, solution.negative = result.negative;
        return 1;
    } else return 0;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll sumA = 0, sumB = 0;
        vector<Function>func; func.clear();
        set<Function>sfunc; sfunc.clear();
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; i++) {
            int a, b; scanf("%d%d", &a, &b);
            sumA += a, sumB += b;
            func.pb(Function(a, b));
        }
        sort(func.begin(), func.end());
        vector<Fraction>zp, ans;
        for (auto i : func) zp.pb(i.zeroPoint);
        Fraction last = Fraction(-int_inf, 1);
        for (auto i : zp) {
            Fraction solution;
            if (solve(func, last, i, solution)) ans.pb(solution);
            last.fm = i.fm, last.fz = i.fz, last.negative = last.negative;
        }
        Fraction solution;
        if (solve(func, last, Fraction(int_inf, 1), solution)) ans.pb(solution);
        if (!(int)ans.size()) puts("-1");
        else {
            printf("%d", (int)ans.size());
            for (auto i : ans) printf(" %d/%d", i.fz * i.negative, i.fm);
            puts("");
        }
    }
    return 0;
}