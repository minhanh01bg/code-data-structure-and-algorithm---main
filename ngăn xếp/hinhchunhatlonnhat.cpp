#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

ll maxa(int a[], int n)
{
    ll mx = 0, tp, i = 0, max_current;
    stack<int> s;
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            max_current = a[tp] * (s.empty() ? i : i - s.top() - 1);
            mx = max(max_current, mx);
        }
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        max_current = a[tp] * (s.empty() ? i : i - s.top() - 1);
        mx = max(max_current, mx);
    }
    return mx;
}
int main()
{
    // fast();
    // run(){
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n - 1)
    cin >> a[i];
    cout << maxa(a, n) << endl;
    // }
}