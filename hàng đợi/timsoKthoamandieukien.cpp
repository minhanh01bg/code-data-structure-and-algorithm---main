/* code by vu minh anh */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
/**/
bool mi(int n)
{
    int k[6], x = 0;
    int p[6];
    for (int i = 0; i <= 5; i++)
        p[i] = 0;
    while (n)
    {
        k[x] = n % 10;
        if (k[x] > 5)
            return false;
        p[k[x]]++;
        n /= 10;
        x++;
    }
    for (int j = 0; j < x; j++)
    {
        if (p[k[j]] > 1)
            return false;
    }
    return true;
}
bool check(int n)
{
    int d = 0;
    while (n)
    {
        d += n % 10;
        if (d > 5)
            return false;
        n /= 10;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    run()
    {
        int l, r;
        cin >> l >> r;
        int k = 0;
        for (int i = l; i <= r; i++)
        {
            if (mi(i))
                k++;
        }
        cout << k << endl;
    }
}