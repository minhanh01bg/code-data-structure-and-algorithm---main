#include <bits/stdc++.h>
#define reset(x) memset(x, 0, sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 100005;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i > (b); i--)
#define REPD(i, a, b) for (int i = (a); i >= (b); i--)
#define TR(it, a) for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define begiN() \
    int t;      \
    cin >> t;   \
    while (t--)
using namespace std;

void printNGE(LL arr[], int n)
{
    stack<LL> s;
    int arr1[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            arr1[i] = -1;
        else
            arr1[i] = s.top();

        s.push(arr[i]);
    }

    FOR(i, 0, n)
    cout << arr1[i] << " ";
}

int main()
{
    fast()
        begiN()
    {
        int n;
        cin >> n;
        LL a[n];
        FOR(i, 0, n)
            cin >> a[i];
        printNGE(a, n);
        cout << endl;
    }
}