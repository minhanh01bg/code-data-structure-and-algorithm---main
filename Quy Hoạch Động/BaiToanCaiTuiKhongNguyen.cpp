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
#define run() int N; cin>>N; cin.ignore(); while(N--)

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(x,C) 						for (auto x:C)

	
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pause() system("pause");

using namespace std;
/*----------------------------------------------------------------*/


bool cmp(pair<double, double>a, pair<double, double>b){
	return a.first / a.second > b.first / b.second;
}
main(){
	faster()
	run(){
		ll a, b;
		cin >> a >> b;
		vector<pair<double, double>> C(a);
		FOR(i, 0, a - 1)
			cin >> C[i].first >> C[i].second;
		sort(C.begin(),C.end(), cmp);
		ll k=0;
		double ans=0;
		FOR(i, 0, a - 1){
			k += C[i].second;
			ans += C[i].first;
			if(k > b){
				ans -= C[i].first;
				k -= C[i].second;
				ans += C[i].first * ((double)(b - k)) / C[i].second;
				break; 
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
}