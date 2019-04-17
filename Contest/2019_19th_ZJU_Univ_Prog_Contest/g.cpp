#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int M[100005], F[100006];

int main(void)
{
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            int n, k;
            scanf("%d %d", &n, &k);
            priority_queue <long long int> pos, neg;
            for (int i = 0; i < n; i++)
            {
                int tmp;
                scanf("%d", &tmp);
                if (tmp > 0)
                {
                    pos.push(tmp);
                }
                else
                {
                    neg.push(-tmp);
                }
            }
            long long int ans = 0, maxn = 0;
            while (!pos.empty())
            {
                ans += 2 * pos.top();
                maxn = max(pos.top(), maxn);
                int cnt = k - 1;
                pos.pop();
                while (cnt-- && !pos.empty())
                {
                    pos.pop();
                }
            }
            while (!neg.empty())
            {
                ans += 2 * neg.top();
                maxn = max(neg.top(), maxn);
                int cnt = k - 1;
                neg.pop();
                while (cnt-- && !neg.empty())
                {
                    neg.pop();
                }
            }
            printf("%lld\n", ans - maxn);
        }
    }
    return 0;
}