#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

main()
{
    fast()
        run()
    {
        int n;
        cin >> n;
        queue<pair<int, int>> Q;
        set<int> s;
        Q.push(make_pair(n, 0));
        pair<int, int> z;
        while (!Q.empty())
        {
            z = Q.front();
            Q.pop();
            if (z.first == 1)
            {
                cout << z.second << endl;
                break;
            }

            for (int i = 2; i * i <= z.first; i++)
            {
                if (z.first % i == 0 && s.find(max(z.first / i, i)) == s.end())
                {
                    Q.push(make_pair(max(i, z.first / i), z.second + 1));
                    s.insert(max(z.first / i, i));
                }
            }

            if (s.find(z.first - 1) == s.end())
            {
                Q.push(make_pair(z.first - 1, z.second + 1));
                s.insert(z.first - 1);
            }
        }
    }
}