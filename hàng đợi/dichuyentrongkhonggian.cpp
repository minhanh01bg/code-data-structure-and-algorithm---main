#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 30;
const int inf = 30 * 30 * 30 + 123;
int dx[] = {0 , 0, -1, 1};
int dy[] = {-1 , 1, 0, 0};
int a, b, c; 
char v[N][N][N];
struct item{
	int i, j, k;
};
bool check(int x, int y){
	if(x < 0 || y < 0 || x >= b || y >= c) return false;
	return true;
}
void BFS(item s, item e){
 
	deque<item> q;
	q.push_front(s);
	int num[N][N][N] = {0};
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++){
				num[i][j][k] = inf;
			}
	num[s.i][s.j][s.k] = 0;
 
	while(!q.empty()){
		item cur = q.front(); q.pop_front();
    	for(int i = 0; i < 4; i++){
    		if(cur.i - 1 >= 0 && v[cur.i - 1][cur.j][cur.k] != '#'){
    			if(num[cur.i - 1][cur.j][cur.k] > num[cur.i][cur.j][cur.k] + 1){
    				num[cur.i - 1][cur.j][cur.k] = num[cur.i][cur.j][cur.k] + 1;
    				q.push_back({cur.i - 1, cur.j, cur.k});
				}
			}
			if(cur.i + 1 < a && v[cur.i + 1][cur.j][cur.k] != '#'){
    			if(num[cur.i + 1][cur.j][cur.k] > num[cur.i][cur.j][cur.k] + 1){
    				num[cur.i + 1][cur.j][cur.k] = num[cur.i][cur.j][cur.k] + 1;
    				q.push_back({cur.i + 1, cur.j, cur.k});
				}
			}
			int x = cur.j + dx[i], y = cur.k + dy[i];
    		if(!check(x, y) || v[cur.i][x][y] == '#') continue;
    		if(num[cur.i][x][y] > num[cur.i][cur.j][cur.k] + 1){
    			num[cur.i][x][y] = num[cur.i][cur.j][cur.k] + 1;
    			q.push_back({cur.i, x, y});
			}
		}
	}
	if(num[e.i][e.j][e.k] >= inf) cout << -1 << endl;
	else cout << num[e.i][e.j][e.k] << endl;
}
void solution(){
	cin >> a >> b >> c;
	item s, e;
	for(int i = 0; i < a; i++)
		for(int j = 0; j < b; j++)
			for(int k = 0; k < c; k++){
				cin >> v[i][j][k];
				if(v[i][j][k] == 'S') s = {i, j, k};
				if(v[i][j][k] == 'E') e = {i, j, k};
			}
			cin.ignore();
 
	BFS(s, e);
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int icase = 1; cin >> icase;
    while(icase--) solution();
	return 0;
}