#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, r, l) for (int i = r; i >= l; i--)
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
bool ok[1001];
int c = 0;
int n, m, x;
vector<vector<int>> a(1001);
void init()
{
    c = 0;
    memset(ok, true, sizeof(ok));
    FOR(i, 0, n)
    a[i].clear();
}

void DFS(int x)
{
    queue<int> qq;
    qq.push(x);
    ok[x] = false;
    int u;
    while (!qq.empty())
    {
        u = qq.front();
        qq.pop();
        FOR(i, 0, a[u].size() - 1)
        {
            if (ok[a[u][i]])
            {
                cout << u << " " << a[u][i] << endl;
                ok[a[u][i]] = false;
                qq.push(a[u][i]);
            }
        }
    }
}

void dfs(int x)
{
    c++;
    ok[x] = false;
    FOR(i, 0, a[x].size() - 1)
    if (ok[a[x][i]])
        dfs(a[x][i]);
}

int main()
{
    fast()
        run()
    {
        cin >> n >> m >> x;
        init();
        int u, v;
        FOR(i, 0, m - 1)
        {
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        dfs(x);
        if (c < n)
        {
            cout << -1 << endl;
            continue;
        }
        memset(ok, true, sizeof(ok));
        DFS(x);
    }
}