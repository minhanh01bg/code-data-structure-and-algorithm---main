#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 20
int n,C[11],k;
bool stop=false;
void init(){
	k=1;
	C[k]=n;
}
void sinh(){
	int i, j, R, S, D;
	i=k;
	while(i>0 && C[i]==1) i--;
	if(i>0){
		C[i]=C[i]-1;D=k-i+1;
		R=D/C[i];S=D%C[i];
		k=i;
		if(R>0){
			FOR(j, i+1,i+R)
				C[j]=C[i];
			k=k+R;
		}
		if(S>0) {
			k=k+1;
			C[k]=S;
		}
		
	}
	else stop=true;
}
void res(){
	cout<<"(";
	FOR(i,1,k){
		if(i!=k)
			cout << C[i] << " ";
		else cout<<C[i];
	}
	cout<<") ";
}
void disi(){
	stop=false;
	while(!stop){
		res();
		sinh();
	}
}
int main(){
	fast();
	run(){
		cin >> n;
		init();
		disi();
		cout<<endl;
	}
}