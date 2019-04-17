#include <bits/stdc++.h>

using namespace std;

// compare all in sta.
int calc(deque <char> a, deque <char> b, int sta)
{
    while (1)
    {
        if ((sta & 1) && (sta & 2) && !(sta & 4) && !(sta & 8) && a.empty())
        {
            if (sta & 1)
            {
                return 1;
            }
            else if (sta & 2)
            {
                return 2;
            }
        }
        if (!(sta & 1) && !(sta & 2) && (sta & 4) && (sta & 8) && b.empty())
        {
            if (sta & 4)
            {
                return 4;
            }
            else if (sta & 8)
            {
                return 8;
            }
        }
        if (a.empty() && b.empty())
        {
            if (sta & 1)
            {
                return 1;
            }
            else if (sta & 2)
            {
                return 2;
            }
            else if (sta & 4)
            {
                return 4;
            }
            else if (sta & 8)
            {
                return 8;
            }
        }
        char sc = 0;

        if (sta == 1 || sta == 2 || sta == 4 || sta == 8)
        {
            return sta;
        }

        if (sta & 1)
        {
            char tmp;
            if (a.size())
            {
                tmp = a.front();
                a.pop_front();
                a.push_front(tmp);
            }
            else
            {
                tmp = 1;
            }
            if (tmp > sc)
            {
                sc = tmp;
            }
        }

        if (sta & 2)
        {
            char tmp;
            if (a.size())
            {
                tmp = a.back();
                a.pop_back();
                a.push_back(tmp);
            }
            else
            {
                tmp = 1;
            }
            if (tmp > sc)
            {
                sc = tmp;
            }
        }

        if (sta & 4)
        {
            char tmp;
            if (b.size())
            {
                tmp = b.front();
                b.pop_front();
                b.push_front(tmp);
            }
            else
            {
                tmp = 1;
            }
            if (tmp > sc)
            {
                sc = tmp;
            }
        }

        if (sta & 8)
        {
            char tmp;
            if (b.size())
            {
                tmp = b.back();
                b.pop_back();
                b.push_back(tmp);
            }
            else
            {
                tmp = 1;
            }
            if (tmp > sc)
            {
                sc = tmp;
            }
        }

        int sel = 0;

        char s1 = 0, s2 = 0, s3 = 0, s4 = 0;

        if (sta & 1)
        {
            char tmp;
            if (a.size())
            {
                tmp = a.front();
                a.pop_front();
                s1 = tmp;
            }
            else
            {
                tmp = 1;
            }
            if (tmp == sc)
            {
                sel |= 1;
            }
        }

        if (sta & 2)
        {
            char tmp;
            if (a.size())
            {
                tmp = a.back();
                a.pop_back();
                s2 = tmp;
            }
            else
            {
                tmp = 1;
            }
            if (tmp == sc)
            {
                sel |= 2;
            }
        }

        if (sta & 4)
        {
            char tmp;
            if (b.size())
            {
                tmp = b.front();
                b.pop_front();
                s3 = tmp;
            }
            else
            {
                tmp = 1;
            }
            if (tmp == sc)
            {
                sel |= 4;
            }
        }

        if (sta & 8)
        {
            char tmp;
            if (b.size())
            {
                tmp = b.back();
                b.pop_back();
                s4 = tmp;
            }
            else
            {
                tmp = 1;
            }
            if (tmp == sc)
            {
                sel |= 8;
            }
        }
        sta = sel;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        string A, B;
        cin >> A >> B;
        cout << "Case #" << c << ": ";
        deque <char> a, b;
        for (auto i : A)
        {
            a.push_back(i);
        }
        for (auto i : B)
        {
            b.push_back(i);
        }
        while (a.size() || b.size())
        {
            char mx = 0;
            int sta = 0;
            if (a.size())
            {
                if (a.front() > mx)
                {
                    mx = a.front();
                }
                if (a.back() > mx)
                {
                    mx = a.back();
                }
            }
            if (b.size())
            {
                if (b.front() > mx)
                {
                    mx = b.front();
                }
                if (b.back() > mx)
                {
                    mx = b.back();
                }
            }

            if (a.size())
            {
                if (a.front() == mx)
                {
                    sta |= 1;
                }
                if (a.back() == mx)
                {
                    sta |= 2;
                }
            }
            if (b.size())
            {
                if (b.front() == mx)
                {
                    sta |= 4;
                }
                if (b.back() == mx)
                {
                    sta |= 8;
                }
            }

            sta = calc(a, b, sta);

            switch (sta)
            {
                case 1:
                    cout << a.front();
                    a.pop_front();
                    break;
                case 2:
                    cout << a.back();
                    a.pop_back();
                    break;
                case 4:
                    cout << b.front();
                    b.pop_front();
                    break;
                case 8:
                    cout << b.back();
                    b.pop_back();
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}