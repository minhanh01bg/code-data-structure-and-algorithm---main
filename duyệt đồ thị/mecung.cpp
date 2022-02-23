#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mecung"
#define ft						first
#define sd						second
#define pb						push_back
#define pf						push_front
#define sz(x)					(int)(x).size()

#define cntone(x)				__builtin_popcountll((x))
#define each(x,y)				for (auto &x: y)
#define all(x)					(x).begin(),(x).end()
#define aln(x,y)				(x)+1,(x)+1+(y)
#define Bonnie					freopen(Nothing".inp","r",stdin),freopen(Nothing".out","w",stdout)
#define FastIO					ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define two(x)					(1ll<<(x))

template<class T, class Y> T offbit(T mask, Y pos) { return (mask & ~((T)1 << pos));}
template<class T, class Y> T onbit(T mask, Y pos) {return (mask | ((T)1 << pos));}
template<class T, class Y> T getbit(T mask, Y pos) {return ((mask >> (T)pos) & (T)1);}
template<class T> bool umax(T& x, T& y) { return x < y ? swap(x, y), 1 : 0;}
template<class T> bool umin(T& x, T& y) { return x > y ? swap(x, y), 1 : 0;}
template<class T> T Modulo(T &A, T B, T mod) { A += B; if (A >= mod) A -= mod; else if (A < 0) A += mod; return A;}
template<class T> T Mod(T &A, T mod) {if (A >= mod) A -= mod; else if (A < 0) A += mod; return A;}

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using LL = int64_t;
using ULL = uint64_t;
using LD = long double;
using ii = pair<int, int>;
const LL MOD = 1e9 + 7;
const int inf = 1e9;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

LL fmul(LL a, LL b, LL mod) {a %= mod; b %= mod; LL q = (LD)a * b / mod; LL r = a * b - q * mod; return (r % mod + mod) % mod;}

///Head

struct Node
{
	int ft, sd, dia;
	Node (int _ft = 0, int _sd = 0, int _dia = 0): ft(_ft), sd(_sd), dia(_dia) {};
};
deque<Node> dq;
deque<ii> pq;
int d[105][105][5], dd[105][105], m, n, res = inf, ret = inf;
char c[105][105];
set<ii> sett;
vector<ii> diamond, start, tr[105][105];
bool Banned(int x, int y)
{
	return (x < 1 || y < 1 || x > m || y > n || c[x][y] == '*');
}
void bfs01()/// for path from diamond 1 to diamond 2
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			d[i][j][0] = d[i][j][1] = d[i][j][2] = inf;
	ii p = diamond[0];
	ii q = diamond[1];
	d[p.ft][p.sd][1] = 0;
	dq.push_front(Node(p.ft, p.sd, 1));
	while (!dq.empty())
	{
		Node u = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int x = u.ft + dx[i];
			int y = u.sd + dy[i];
			if (Banned(x, y)) continue;
			if (make_pair(x, y) == p) continue;
			int ndia = u.dia;
			if (c[x][y] == '$') ndia++;
			if (d[u.ft][u.sd][u.dia] + (c[x][y] == '#') < d[x][y][ndia])
			{
				d[x][y][ndia] = d[u.ft][u.sd][u.dia] + (c[x][y] == '#');
				tr[x][y].clear();
				tr[x][y].pb({u.ft, u.sd});
				int w = (c[x][y] == '#');

				if (make_pair(x, y) == q) continue;
				if (w == 1) dq.push_back(Node(x, y, ndia));
				else dq.push_front(Node(x, y, ndia));
			}
			else if (d[u.ft][u.sd][u.dia] + (c[x][y] == '#') == d[x][y][ndia])
				tr[x][y].pb({u.ft, u.sd});
		}
	}

	res = d[q.ft][q.sd][2];
}
void bfs()///from edge
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			dd[i][j] = inf;
	ii p = pq.front();
	dd[p.ft][p.sd] = c[p.ft][p.sd] == '#';
	while (!pq.empty())
	{
		ii u = pq.front();
		pq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int x = u.ft + dx[i];
			int y = u.sd + dy[i];

			if (Banned(x, y)) continue;
			int w = c[x][y] == '#';
			if (dd[u.ft][u.sd] + w < dd[x][y])
			{
				dd[x][y] = dd[u.ft][u.sd] + w;
				if (w == 1)  pq.push_back({x, y});
				else pq.push_front({x, y});
			}
		}
	}
	for (ii k : sett)
		ret = min(ret, dd[k.ft][k.sd] - (c[k.ft][k.sd] == '#'));
}
void trace(int x, int y)
{
	queue<ii> q;
	q.push(ii(x, y));
	while (!q.empty())
	{
		ii u = q.front();
		q.pop();
		for (ii k : tr[u.ft][u.sd])
		{	if (sett.find(k) == sett.end())
			{
				q.push(k);
				sett.insert(k);
			}
		}
	}
}
void prep()
{
	bfs01();
	trace(diamond[1].ft, diamond[1].sd);
	for (ii k : start)
	{
		pq.push_front(k);
		bfs();
	}

	cout << res + ret << "\n";
}
signed main()
{
	FastIO;
	//Bonnie;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '$') diamond.pb({i, j});
			if (i == 1 || j == 1 || i == m || j == n)
				if (c[i][j] != '*') start.pb({i, j});
		}
	prep();
	return 0;
}