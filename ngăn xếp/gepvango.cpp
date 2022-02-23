#include<bits/stdc++.h>
#define reset(x) memset(x,0,sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define run() int t;cin>>t;while(t--)
using namespace std;

int const N = 1e5 + 123;
void TestCase() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto&x : v) cin>>x;
	vector<int> st;
	vector<int> greater(n), less(n);
 
	REPD(i,n-1,0){
		while(!st.empty() && v[i] <= v[st.back()]) st.pop_back();
		if(st.empty()) greater[i] = -1;
		else greater[i] = st.back();
		st.push_back(i);
	}
	st.clear();
 
	FOR(i,0,n){
		while(!st.empty() && v[i] <= v[st.back()]) st.pop_back();
		if(st.empty()) less[i] = -1;
		else less[i] = st.back();
		st.push_back(i);
	}
 
	int mx = -1;
	FOR(i, 0, n){
		int x = less[i];
		int y = greater[i];
		y = (y == -1) ? n : y;
		int calc = (i - x + y - i - 1);
		if(calc >= v[i]) mx = max(mx, v[i]);
	}
	if(mx == -1) mx = 0;
	cout << mx << endl;
}
 
int main() {
    fast()
	run(){
		TestCase();
	}
    return EXIT_SUCCESS;
}