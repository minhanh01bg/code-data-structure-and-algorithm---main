#include <bits/stdc++.h>

using namespace std;
// code by vu minh anh
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, l, r) for (int i = l; i >= r; i--)
#define BEGIN() \
    int t;      \
    cin >> t;   \
    while (t--)
#define FAST()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define RESET(C) memset(C, 0, sizeof(C))
const ll mod = 1e9 + 7;
//
void psdv(ll p, ll q)
{
    if (q % p == 0)
    {
        cout << 1 << "/" << q / p;
    }
    else
    {
        ll n = q / p + 1;
        cout << 1 << "/" << n << " + ";
        psdv(p * n - q, q * n);
    }
}
int main()
{
    FAST()
    BEGIN()
    {
        ll p, q;
        cin >> p >> q;
        psdv(p, q);
        cout << endl;
    }
}