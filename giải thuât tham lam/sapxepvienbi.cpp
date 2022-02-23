#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define BEGIN() int t;cin>>t;while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define reset(C) memset(C,0,sizeof(C))
#define endl "\n"
int main() {
	faster();
	ll a;
	string b = "";
	char k;
	ll C[3];
	reset(C);
	cin >> a;
	FOR(i,0,a-1) {
		cin >> k;
		b += k;
		if (k == 'X') C[0]++;
		if (k == 'T') C[1]++;
		if (k == 'D') C[2]++;
	}
	ll total = 0;
	FOR(i,0,C[0] - 1){
		if (b[i] == 'T'){
			FOR(j,C[0], a - 1) {
				if (b[j] == 'X') {
					swap(b[i], b[j]);
					total++;
					break;
				}
			}
		}
		else if (b[i] == 'D'){
			FORD(j, a - 1, C[0]){
				if (b[j] == 'X'){
					swap(b[i], b[j]);
					total++;
					break;
				}
			}
		}
	}
	FOR(i, C[0], C[0] + C[1] - 1) {
		if (b[i] == 'D'){
			FOR(j, C[0] + C[1], a - 1) {
				if (b[j] == 'T') {
					swap(b[i], b[j]);
					total++;
					break;
				}
			}
		}
    }
	cout << total << endl;
}