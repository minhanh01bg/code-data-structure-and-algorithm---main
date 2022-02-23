#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"

#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long

int a[100],n;
vector<string> res;
string s;
void Try(int i){
	FOR(j,a[i-1]+1,n){
		a[i]=j;
		FOR(l,1,i) cout<<s[a[l]-1];
		cout<<" ";
		if(i<n) Try(i+1);
	}
}

int main() {
	faster()
    run(){	
		cin>>n>>s;
		Try(1);
		cout<<endl;
	}
	return 0;
}