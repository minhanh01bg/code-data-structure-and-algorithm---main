#include<bits/stdc++.h>

using namespace std;

#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
#define endl "\n"
//ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG	
int B[1001][1001];
bool ok[1001];
int u,n,m;int BB[1001],kkkk=0;
int truoc[1001];
void BFS(int i){
    queue<int> hd;
    // cout<<u<<" ";
    ok[i]=true;
    hd.push(i);
    while(!hd.empty()){
        int s = hd.front();
        hd.pop();
        for(int v=1;v<=u;v++){
            if(B[s][v]==1&&ok[v]==false){
                // cout<<v<<" ";
				truoc[v]=s;
                ok[v] =	true;
                hd.push(v);
            }
        }
    }
}
void init(){
	kkkk=0;
	for(int i=1;i<=u;i++) 
		truoc[i]=0;
	
	for(int i=1;i<=u;i++) 
		ok[i]=false;

	for(int i=1;i<=u;i++)
		for(int j=1;j<=u;j++)
			B[i][j]=0;
}

void duongdi(){
	if(truoc[m]==0) {
		cout<<"-1";
		return;
	}
	int j=m;
	BB[kkkk++]=j;
	while(truoc[j]!=n){
		BB[kkkk++]=truoc[j];
		j=truoc[j];
	}
	BB[kkkk]=n;
	for(int i=kkkk;i>=0;i--) cout<<BB[i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int v;
        cin>>u>>v>>n>>m;
        int U,V;
        init();
        for(int i=1;i<=v;i++){
            cin >> U >> V;
            B[U][V]=1;
            // B[V][U]=1;
        }
        // DFS(n);
		BFS(n);
		duongdi();
        cout<<endl;
    }
}