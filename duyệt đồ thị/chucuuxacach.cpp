#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define endl      <<endl
#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX
// #define m         %u

#define er              erase
#define pb              push_back
#define eleV            vector <ele>
#define all(vec)        vec.begin(), vec.end()
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define neg_pq(x)       priority_queue<x, vector<x>, greater<x>>
#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y, 0))

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //

vector<vector<int>> pv(10001);
int a[1001][1001], cnt;
int n, m, x, y, k, xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1};

bool isSafe(int inx, int iny)
{
    if (inx <= 0 || iny <= 0 || inx > n || iny > n)
        return false;
    return true;
}

void mark(int inx, int iny)
{
    cnt += a[inx][iny];
    a[inx][iny] = -1;
    FOR(i, 0, 4)
    {
        x = inx + xi[i]; y = iny + yi[i];
        
        if (!isSafe(x,y) || a[x][y] < 0)
            continue;
        int z1 = (inx - 1) * n + iny;
        int z2 = (x   - 1) * n +  y ;
        int flag = 1;
        FOR(i, 0, pv[z1].size())
            if (pv[z1][i] == z2)
            {
                flag = 0;
                break;
            }
        if (flag) mark(x,y);
    }
}

int main ()
{
    faster();
    rs(a,0);
    vector<ll> s; ll ans = 0;
    int x1, x2, y1, y2, z1, z2;
    cin >> n >> k >> m;
    pv.resize(n * n + 1);

    FOR(i, 0, m)
    {
        cin >> x1 >> y1; z2 = (x1 - 1) * n + y1;
        cin >> x2 >> y2; z1 = (x2 - 1) * n + y2;
        
        pv[z2].pb(z1);
        pv[z1].pb(z2);
    }

    FOR(i, 0, k)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }

    FOR(i, 1, n + 1)
        FOR(j, 1, n + 1)
            if (a[i][j] >= 0)
            {
                cnt = 0;
                mark(i,j);
                if (cnt)
                    s.pb(cnt);
            }

    FOR(i, 0, s.size())
        FOR(j, i + 1, s.size())
            ans += s[i] * s[j];

    if (s.size() == 1) ans = s[0];
    if (s.size() == 0) ans = 0;

    cout << ans endl;
}