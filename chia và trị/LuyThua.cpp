#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 +7;
long long n,k;
long long tinh(long long n, long long k){
	if( k == 0 ) return 1;
	long long tmp = tinh(n,k/2);
	tmp = (tmp*tmp)%mod;
	if( k & 1 ) tmp = (tmp*n)%mod;
	return tmp;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        cin >>n>>k;
        cout << tinh(n,k)<<endl;
    }
}