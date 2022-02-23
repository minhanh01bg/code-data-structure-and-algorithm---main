#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0)
// #define end return 
#define pb push_back

int a[11], n, k, b[11][11];
bool stop=false;
void init(){
	for(int i=1;i<=n;i++)
		a[i]=i;
}

void sinh(){
	int i=n-1;
	while(i>0&&a[i]>a[i+1]) i--;
	if(i==0) stop=true;
	else {
		int K=n;
		while(a[i]>a[K]) K--;
		swap(a[i],a[K]);
		int c=n,r=i+1;
		while(r < c){
			swap(a[r],a[c]);
			r++;c--;
		}
	}
}
int d=0;
int B[1000],kk=1;
void output(){
	int sum=0;
	for(int i=1;i<=n;i++) 
		sum+=b[i][a[i]];
	if(sum==k) {
		d++;
		for(int i=1;i<=n;i++)
			B[kk++]=a[i];
	
	}
}

int main(){
	fast();
	cin>>n>>k;
	init();
	stop=false;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	while(!stop){
		output();
		sinh();
	}
	cout<<d<<endl;
	for(int i=1;i<kk;i++){
		int	x=0;
		if(	i%n==0){
			x=1;
		} 
		cout<<B[i]<<" ";
		if(x==1) cout<<endl;
	}
}