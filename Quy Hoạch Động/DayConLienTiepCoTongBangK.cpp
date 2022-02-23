#include <bits/stdc++.h>
using namespace std;
#define Nothing "mikey"
#define Nothing "mikey"
#define Nothing "mikey"
#define Nothing "mikey"
#define Nothing "mikey"
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define ll long long
/*---------------------------------------------------------------*/
main()
{
    faster()
        run()
    {
        int n;
        ll k;
        cin >> n >> k;
        ll sum = 0;
        ll a[n], y = 1;
        FOR(i, 0, n - 1)
        {
            cin >> a[i];
            if (a[i] == 0)
                y = 0;
        }
        int start = 0, x = 0;
        if (k == 0 && y != 0)
        {
            cout << "NO\n";
            continue;
        }
        if (k == 0 && y == 0)
        {
            cout << "YES\n";
            continue;
        }
        FOR(i, 0, n - 1)
        {
            sum += a[i];
            while (sum > k)
            {
                sum -= a[start++];
            }
            if (sum == k)
            {
                x = 1;
                cout << "YES\n";
                break;
            }
        }
        if (x == 0)
            cout << "NO\n";
    }
    return 0;
}