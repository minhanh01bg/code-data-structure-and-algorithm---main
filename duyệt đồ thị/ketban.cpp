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
#define vi vector<int>
const int N = 100005;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i > (b); i--)
#define REPD(i, a, b) for (int i = (a); i >= (b); i--)
#define TR(it, a) for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define BEGIN \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long
#define endl "\n"

vector<vi> edge(100005);
vector<bool> visited(100005, false);

int dfs(int u)
{
    int ans = 1;
    visited[u] = true;
    FOR(i, 0, edge[u].size())
    {
        if (visited[edge[u][i]] == false)
        {
            ans += dfs(edge[u][i]);
        }
    }
    return ans;
}

void process()
{
    for (int i = 1; i < 100005; i++)
    {
        edge[i].clear();
        visited[i] = false;
    }
    int n, m;
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int res = 0;
    REP(i, 1, n)
    {
        if (visited[i] == false)
        {
            res = max(res, dfs(i));
        }
    }
    cout << res << endl;
}

int main()
{
    FAST
        BEGIN
        process();

    return 0;
}