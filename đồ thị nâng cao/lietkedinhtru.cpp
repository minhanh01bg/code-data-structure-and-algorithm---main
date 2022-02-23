//LIỆT KÊ ĐỈNH TRỤ
#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int n,m;
int B[1001][1001];
bool ok[1001];
void DFS(int u){
	ok[u]=false;
	FOR(i, 1, n)
		if(B[u][i]&&ok[i])
			DFS(i);
}
void init(){
	FOR(i,1,n)
		ok[i]=true;
}

bool tes(){
	FOR(i,1,n)
		if(ok[i]==true) return true;
	return false;
}
void mi(){
	init();
	FOR(i,1,n){
		ok[i]=false;
		if(i==1) DFS(2);
		else DFS(1);
		if(tes()) cout<<i<<" ";
		init();
	}
}
int main(){
	fast();
	run(){
		cin>>n>>m;
		int u,v;
		FOR(i, 1, n)
			FOR(j, 1, n)
				B[i][j]=0;
		FOR(i, 1, m){
			cin>>u>>v;
			B[u][v]=1;
			B[v][u]=1;
		}
		mi();
		cout<<endl;	
	}
}