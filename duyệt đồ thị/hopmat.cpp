#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define endl      <<endl
#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX
// #define m         %u

#define res(x)          resize(x)
#define sz()            size()
#define er              erase
#define pb              push_back
#define eleV            vector <ele>
#define all(vec)        vec.begin(), vec.end()
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define neg_pq(x)       priority_queue<x, vector<x>, greater<x>>
#define vec2(C,x,y,tp)  vector<vector<tp> > C(x, vector<tp> (y, 0))
#define vec(x)          vector<vector<x>> 

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //

vec(int) s(1005); vector<int> a;
int n, m, k, p[1005];
bool vs[1005];
void reset();
void getip();

void dfs(int u)
{
    vs[u] = true; p[u]++;

    FOR(i, 0, s[u].sz())
        if (vs[s[u][i]] == false)
            dfs(s[u][i]);
}

void solve()
{
    int ans = 0;

    FOR(i, 0, k)
    {
        rs(vs, false);
        dfs(a[i]);
    }

    FOR(i, 0, 1005)
        if (p[i] == k)
            ans++;
    cout << ans;
}

int main ()
{
    faster();
    // run()
    {
        cin >> k >> n >> m;
        reset();
        getip();
        solve();
    }
    return 0;
}


// --------------------------------------------------------- //
void getip()
{
    int x, y;
    FOR(i, 0, k)
    {
        cin >> x;
        a.pb(x);
    }
    FOR(i, 0, m)
    {
        cin >> x >> y;
        s[x].pb(y);
    }
}

void reset()
{
    rs(p, 0);
    rs(vs, false);
    a.clear();
    FOR(i, 0, n + 1) s[i].clear();
}