/* code by vu minh anh */\
//234	DSA08020	BIẾN ĐỔI SỐ NGUYÊN TỐ
#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() int t;cin>>t;while(t--)

#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int M,N;
vector<int>a;
vector<int>ke[100000];
int dem[100000];
bool ok[100000];
queue<int> hd;
bool prime(int n){
	FOR(i, 2, sqrt(n))
		if(n % i == 0 ) return false;
	return true;
}

bool check(int x, int y){
	int d=0;
	while(x){
		if(x%10 != y%10) {
			d++;
			if(d > 1) return false;
		}
		x/=10,y/=10;
	}
	if(d == 1) return true;
	return false;
}

void km(){
	FOR(i,0,a.size()-2){
		FOR(j,i+1,a.size()-1){
			if(check(a[i],a[j])){
				ke[a[i]].push_back(a[j]);
				ke[a[j]].push_back(a[i]);
			}
		}
	}
}
int BFS(int u){
	dem[u] = 0;
    hd.push(u);
    while(!hd.empty()){
        u = hd.front(); hd.pop();
		ok[u] = true;
		if(u == N) 
			return dem[u];
        FOR(i,0,ke[u].size()-1){
			int v=ke[u][i];
            if(ok[v]) continue;
			ok[v] = true;
			dem[v]=dem[u]+1;
			hd.push(v);
        }
    }
}
int main(){
	FOR(i,1000,9999)
		if(prime(i)) 
			a.push_back(i);
	km();
	fast();
	run(){
		cin >> M>> N;
		FOR(i,0,10000) {
			ok[i]=false;
			dem[i]=0;
		}
		while(hd.size()) hd.pop();
		cout<<BFS(M)<<endl;
	}
}