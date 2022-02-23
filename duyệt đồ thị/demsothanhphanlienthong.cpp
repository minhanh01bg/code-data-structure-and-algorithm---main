#include<bits/stdc++.h>

using namespace std;
//TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS	
//ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
#define endl "\n"
int n,a[1001][1001],m;
bool ok[1001];
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=0;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
	for(int i=1;i<=n;i++) 
		ok[i]=true;
}
void BFS(int u){
    queue<int> hd;
    // cout<<u<<" ";
    ok[u]=false;
    hd.push(u);
    while(!hd.empty()){
        int s = hd.front();
        hd.pop();
        for(int i=1;i<=n;i++){
            if(a[s][i]==1&&ok[i]==true){
                // cout<<i<<" ";
                ok[i] = false;
                hd.push(i);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    run(){  
        // string s;
        // cin>>s;
        init();
		int count=0;
		for(int i=1;i<=n;i++){
			if(ok[i]){
				count++;
				BFS(i);
			}
		}
		cout<<count<<endl;
    }
}