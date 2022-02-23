#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define MAX 20
int a[MAX],n;
bool stop = false;
int main(){
	fast();
	run(){
		int n, m;
		cin >> n >> m;
		int a[n],b[m];
		FOR(i,0,n-1)
			cin>>a[i];
		FOR(i,0,m-1)
			cin>>b[i];
		int B[(n-1)+(m-1)+1]={0};
		// B[0]=a[0]*b[0];
		// B[(n-1)*(m-1)]=a[n-1]*b[n-1];
        //code lõi
        FOR(i,0,n-1){
			FOR(j,0,m-1){
				B[i+j]+=a[i]*b[j];
			}
		}
		FOR(i,0,(n-1)+(m-1))
			cout<<B[i]<<" ";
		cout<<endl;
		
	}
}