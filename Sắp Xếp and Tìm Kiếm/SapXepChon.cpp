#include <bits/stdc++.h>
using namespace std;

void sol(int a[], int n)
{
    pair<int, int> p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p, p + n);
    vector<bool> check(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[i] || p[i].second == i)
            continue;

        int cnt = 0;
        int j = i;
        while (!check[j])
        {
            check[j] = 1;
            j = p[j].second;
            cnt++;
        }
        if (cnt > 0)
        {
            ans += (cnt - 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sol(a, n);
    }
}