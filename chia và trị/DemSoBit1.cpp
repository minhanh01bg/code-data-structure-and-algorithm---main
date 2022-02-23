#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run() int test; cin>>test; cin.ignore(); while(test--)

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(x,C) 						for (auto x:C)

#define reset(C) 						memset(C,0,sizeof(C))
#define clearQueue(C, x) 				C = queue<x> ()
#define Fill(C,a) 						fill(C.begin(), C.end(), a)


#define SORTC(C,check) 					sort(C.begin(), C.end(), check)

#define um(x,y) 				unordered_map<x,y> 
#define m(x,y) 					map<x,y> 
#define p(x,y) 					pair<x,y> 
#define us(x) 					unordered_set<x> 
#define vec(x) 					vector<x> 
#define vec2(C,x,y,token) 		vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) 					priority_queue<x>
#define reverse_pq(x) 			priority_queue<x, vector<x>, greater<x> >

	// System

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pause() system("pause");

#define ll long long
using namespace std;

ll findsize(ll n){
	if(n==0) return (ll)1;
	if(n==1) return (ll)1;
	ll size=2*findsize(n/2)+1;
	return size;
}

ll bit1(ll n, ll l, ll r){
	if(n<=1) return n;
	ll res=0;
	ll m=n/2;
	ll size_m=findsize(m);
	if(l<=size_m) res+=bit1(n/2,l,min(size_m,r));// tim ben trai
	if(l<=size_m+1 && size_m+1<=r) res+= n%2;// == vt trung tam
	if(size_m+1<r) res+=bit1(n/2, max((ll)1, l-size_m-1), r-size_m-1);// tim ben doi xung
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
    cin>>t;
    ll n,l,r;
    while(t--){
    	cin>>n>>l>>r;
		cout<<bit1(n,l,r);
        cout<<endl;
    }
	return 0;
}