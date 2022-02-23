#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FOR2(i,a,b) for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define FORA(x,C) for (auto x:C)
#define WHILE(x,y) while(cin>>x>>y)
#define WHILEF(x,y,f) while(f>>x>>y)
#define WHILE2(x) while(cin>>x)
#define WHILEGL(a) while(getline(cin,a))
#define WHILEGLF(a,f) while(getline(f,a))
		
#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
#define ite(y,x,it) y<x>::iterator it

#define reset(C) memset(C,0,sizeof(C))
#define clearQueue(C, x) C = queue<x> ()
#define Fill(C,a) fill(C.begin(), C.end(), a)

#define um(x,y) unordered_map<x,y> 
#define m(x,y) map<x,y> 
#define p(x,y) pair<x,y> 
#define us(x) unordered_set<x> 
#define vec(x) vector<x> 
#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) priority_queue<x>
#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

/*
map<ll, ll> level, lft, rgt;

void DFS(ll x, ll i) {
	if (i == 0) level[x] = 1;
	else level[x] = i;
	if (lft[x]) DFS(lft[x], i + 1);
	if (rgt[x]) DFS(rgt[x], i + 1);
}

void PRINT(ll k) {
	queue<ll> A;
	A.push(k);
	while (!A.empty()) {
		ll x = A.front();
		cout << x << ' ';
		if (lft[x]) A.push(lft[x]);
		if (rgt[x]) A.push(rgt[x]);
		A.pop();
	}
}

int main() {
	faster();
	Begin() {
		ll a;
		cin >> a;
		lft.clear();
		level.clear();
		rgt.clear();
		FOR(i, 0, a - 1) {
			ll x, y;
			cin >> x >> y;
			char token;
			cin >> token;
			if (token == 'L') lft[x] = y;
			if (token == 'R') rgt[x] = y;
			DFS(x, level[x]);
		}
		m(ll,ll)::iterator it;
		ll k;
		for (it = level.begin(); it != level.end(); ++it) {
			if (it->second == 1) {
				k = it->first;
				break;
			}
		}
		PRINT(k);
		cout << endl;
	}
}*/
