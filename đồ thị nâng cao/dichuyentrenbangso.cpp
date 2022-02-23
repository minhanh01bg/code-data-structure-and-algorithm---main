#include <bits/stdc++.h>
using namespace std;

#define pii       pair<int, int>
#define MIN       INT_MIN
#define MAX       LLONG_MAX
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

const int oo = 1e9;
int n, m, d[501][501], arr[501][501];
int xi[4] = {-1, 0, 1, 0},
    yi[4] = {0, 1, 0, -1};

void getip() {
    cin >> n >> m;
    FOR(i, 1, n + 1)
        FOR(j, 1, m + 1)
        {
            cin >> arr[i][j];
            d[i][j] = oo;
        }
}

bool iS(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dijkstra() 
{
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    d[1][1] = arr[1][1];
    pq.push(pii(1,1));

    while (pq.size())  {
        pii tmp = pq.top();
        pq.pop();

        FOR(i, 0, 4)  {
            int x = tmp.first + xi[i], y = tmp.second + yi[i];

            if (iS(x,y) == false) continue;
            if (d[x][y] > d[tmp.first][tmp.second] + arr[x][y])  {
                d[x][y] = d[tmp.first][tmp.second] + arr[x][y];
                pq.push(pii(x,y));
            }
        }
    }
}

void solve() {
    dijkstra();
    cout << d[n][m] << endl;
}

int main () {
    faster();
    run() {
        getip();
        solve();
    }
    return 0;
}