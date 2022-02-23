#include <bits/stdc++.h>
using namespace std;
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


int main()
{
    faster()
        run()
    {
        int n;
        cin >> n;
        int arr[n];
        FOR(i, 0, n - 1)
            cin >> arr[i];
        sort(arr, arr + n);
        cout << arr[(n - 1) / 2] << endl;
    }
    return EXIT_SUCCESS;
}

