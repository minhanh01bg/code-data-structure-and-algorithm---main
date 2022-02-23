#include <bits/stdc++.h>

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
using namespace std;

int n, m, res;
int dsCanh[25][25], dsKe[25][25];
bool ok[25][25];
void reset() {
	rs(dsKe, 0);
	rs(ok, false);
}
void getip() {
	cin >> n >> m;
	reset();
	FOR(i, 0, m) cin >> dsCanh[i][0] >> dsCanh[i][1];
}


void Try(int i, int dem)  {
	FOR(j, 0, n) {
		if(dsKe[i][j]==1 && ok[i][j] == false)  {
			ok[i][j] = true;
			ok[j][i] = true;
			res = max(res, dem + 1);
			Try(j, dem + 1);
			ok[i][j] = false;
			ok[j][i] = false;
		}
	}
}

void solve() {
	FOR(i, 0, m)  {
		dsKe[dsCanh[i][0]][dsCanh[i][1]]=1;
		dsKe[dsCanh[i][1]][dsCanh[i][0]]=1;
	}

    res = 0;
	FOR(i, 0, n) Try(i,0);
	cout << res << endl;
}

main (){
    faster();
    run() {
        getip();
        solve();
    }
    return 0;
}