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
            int n, m;
            priority_queue <int, vector<int>, greater <int>> fu, fd, mu, md;
            scanf("%d %d", &n, &m);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &M[i]);
            }
            for (int i = 0; i < m; i++)
            {
                scanf("%d", &F[i]);
            }
            for (int i = 0; i < n; i++)
            {
                int flag;
                scanf("%d", &flag);
                if (flag)
                {
                    mu.push(M[i]);
                }
                else
                {
                    md.push(M[i]);
                }
            }
            for (int i = 0; i < m; i++)
            {
                int flag;
                scanf("%d", &flag);
                if (flag)
                {
                    fu.push(F[i]);
                }
                else
                {
                    fd.push(F[i]);
                }
            }
            int ans = 0;
            // fu <-> md
            while (!fu.empty() && !md.empty())
            {
                if (fu.top() < md.top())
                {
//                  printf("pop: %d %d\n", fu.top(), md.top());
                    fu.pop();
                    md.pop();
                    ans++;
                }
                else
                {
//                  printf("pop: %d\n", md.top());
                    md.pop();
                }
            }
            // fd <-> mu
            while (!mu.empty() && !fd.empty())
            {
                if (mu.top() < fd.top())
                {
//                  printf("pop: %d %d\n", mu.top(), fd.top());
                    mu.pop();
                    fd.pop();
                    ans++;
                }
                else
                {
//                  printf("pop: %d\n", fd.top());
                    fd.pop();
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}