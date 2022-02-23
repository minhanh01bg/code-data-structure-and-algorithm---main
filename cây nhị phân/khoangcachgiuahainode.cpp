#include <bits/stdc++.h>

#define reset(A,x) memset(A, x, sizeof(A))
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORx(i, m, n, x) for(int i = m; i < n; i += x)
#define FORD(i, m, n) for(int i = m; i >= n; --i)
#define get(C,a) for(int i=0; i<a; i++) cin >> C[i]
#define faster() cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run() int t; cin >> t; while (t--)
// --------------------------------------------------------- //
using namespace std;
int n, q, u, z, ver1, ver2, trc[1001], level[1001]; vector <vector<int>> s;
bool visit[1001];

void dfs(int x) {
    visit[x] = true;
    FOR(i, 0, s[x].size())
        if (visit[s[x][i]] == false) {
            level[s[x][i]] = level[x] + 1;
            dfs(s[x][i]);
        }
}

int main () {
    faster();
    run() {
        s.clear(); reset(visit, false); reset(trc, 0); reset(level, 0);
        level[1] = 1;
        cin >> n;
        vector <int> F(0);
		FOR(i, 0, n + 1) s.push_back(F);
        FOR(i, 1, n) {
            cin >> ver1 >> ver2;
            s[ver1].push_back(ver2);
            trc[ver2] = ver1;
        }
        dfs(1);
        cin >> q;
        while (q--) {
            int n1 = 0, n2 = 0;
            cin >> u >> z;
            if (level[u] < level[z])
                swap(u, z);
            while (level[u] > level[z]) {
                u = trc[u];
                n1++;
            }
            while (u != z) {
                u = trc[u];
                z = trc[z];
                n1++;
                n2++;
            }
            cout << n1 + n2 << endl;
        }
    }
    return EXIT_SUCCESS;
}