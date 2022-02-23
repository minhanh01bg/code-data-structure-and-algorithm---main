#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define	FORD(i,a,b) for(int i=a;i>=b;i--)
#define is insert
#define ll long long
using namespace std;
int main(){
//	set<int>s;
//	ll N=1;
//	s.insert(N);
//	FOR(i,1,1000){
//		N = *s.begin();
//		s.erase(s.begin());
//		s.is(2*N);
//		s.is(3*N);
//		s.is(5*N);
//	}		
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int>s;
		ll N=1;
		s.insert(N);
		FOR(i,1,n-1){
			N = *s.begin();
			s.erase(s.begin());
			s.is(2*N);
			s.is(3*N);
			s.is(5*N);
		}	
		cout<<*s.begin()<<endl;
	}
}