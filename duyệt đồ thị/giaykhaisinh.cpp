#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
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
		
// Get values

#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
#define ite(y,x,it) y<x>::iterator it

// Clear containers

#define reset(C) memset(C,0,sizeof(C))
#define clearQueue(C, x) C = queue<x> ()
#define Fill(C,a) fill(C.begin(), C.end(), a)

// Customize containers
		
#define SORT(C) sort(C.begin(), C.end())
#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
#define SORTC(C,check) sort(C.begin(), C.end(), check)
#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
#define revrs(C) reverse(C.begin(), C.end())
// Containers

#define um(x,y) unordered_map<x,y> 
#define m(x,y) map<x,y> 
#define p(x,y) pair<x,y> 
#define us(x) unordered_set<x> 
#define vec(x) vector<x> 
#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) priority_queue<x>
#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >

// System

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pause() system("pause");

// Namespaces

using namespace std;

map<string, ll> saved;

map<string, string> parents;

map<string, ll> ages;

map<string, ll> ages_when_born;

ll Process(string dad, string son) {
	if (ages[son] != -1) return ages[son];
	if (ages[dad] != -1) return ages[dad] - ages_when_born[son];
	ll k = Process(parents[dad], dad);
	ages[son] = k - ages_when_born[son];
	return ages[son];
}

bool cmp(p(string, ll) a, p(string, ll) b) {
	return a.s > b.s;
}

int main()
{
	faster();
	int N;
	cin >> N;
	FOR(I, 1, N) {
		ages.clear();
		saved.clear();
		parents.clear();
		ages_when_born.clear();
		ll a;
		cin >> a;
		vec(string) C;
		C.clear();
		string x, y;
		ll z;
		vec(string) F[a];
		FOR(i, 0, a - 1) {
			cin >> x >> y >> z;
			if (!saved[x]) saved[x] = 1;
			if (!saved[y]) saved[y] = 1;
			parents[y] = x;
			ages[x] = -1;
			ages[y] = -1;
			F[i].pb(x);
			F[i].pb(y);
			ages_when_born[F[i][1]] = z;
//			F2[i] = z;
		}
		ages["Ted"] = 100;
//		cout << Process("Ted", "Bill") << endl;
//		cout << ages["Ted"] - ages_when_born["Bill"] << endl;
		FOR(i, 0, a - 1) {
			ages[F[i][1]] = Process(F[i][0], F[i][1]);
		}
		cout << "DATASET " << I << endl;
		p(string, ll) P;
		vec(p(string, ll)) A;
		A.clear();
		map<string, ll>::iterator it;
		for (it = ages.begin(); it != ages.end(); ++it) {
			P.f = it->f;
			P.s = it->s;
			A.pb(P);
		}
		SORTC(A, cmp);
		A.erase(A.begin());
		FOR(i, 0, A.size() - 1 ) cout << A[i].f << ' ' << A[i].s << endl;
	}
    return EXIT_SUCCESS;
}