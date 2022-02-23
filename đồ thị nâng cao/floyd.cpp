#include <bits/stdc++.h>
using namespace std;

#define ll              long long
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

#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //

int a[105][105];
int n, m, oo = 1000111000;
vector<int> adja_list[105];

void reset() {
    FOR(i, 1, n + 1) FOR(j, 1, n + 1)
        a[i][j] = oo;

    FOR(i, 1, n + 1)
        a[i][i] = 0;

    FOR(i, 0, 105) 
        adja_list[i].clear();
}

void getip() {
    cin >> n >> m;
    reset();

    int p, q, w;
    FOR(i, 0, m) {
        cin >> p >> q >> w;
        
        a[p][q] = a[q][p] = w;
        adja_list[q].pb(p);
        adja_list[p].pb(q);
    }
}

void zzfloydzz() {
    FOR(k, 1, n + 1) {
        FOR(i, 0, adja_list[k].sz() - 1) {
            int u = adja_list[k][i];
            FOR(j, i + 1, adja_list[k].sz()) {
                int v = adja_list[k][j]; 
                if (a[u][v] > a[u][k] + a[k][v]) {
                    if (a[u][v] == oo) {
                        adja_list[u].pb(v);
                        adja_list[v].pb(u);
                    }

                    a[u][v] = a[u][k] + a[k][v];
                    a[v][u] = a[u][k] + a[k][v];
                }
            }
        }
    }
}

void solve() {
    zzfloydzz();
    run() {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
}

int main () {
    faster();
    getip();
    solve();
    return EXIT_SUCCESS;
}