#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define rs(A,x)         memset(A, x, sizeof(A))
#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define pq(x)           priority_queue<x>
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

// --------------------------------------------------------- //
vector<int> v[1005];
int xet[1005];
int n,m,d;

bool check(int u,int i) {
	FOR(j, 0, v[u].size())
		if (i == xet[v[u][j]]) 
            return false;
	return true;
}

bool Try(int u) {
	if (u == n + 1) 
        return true;
	FOR(i, 1, d + 1) {
		if (check(u,i)) {
			xet[u] = i;
			if (Try(u + 1)) 
                return true;
			xet[u]=0;
		}
	}
	return false;
}

int main() {   
    faster();
    run() {
        FOR(i, 0, 1005) v[i].clear();
        rs(xet, 0);
        cin >> n >> m >> d;
        //d là số màu 
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        if(Try(1)) 
            cout << "YES"<<endl;
        else 
            cout << "NO" <<endl;
    }
}