#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long u =1e9 +7, k; int n;
int MOD=1e9+7;
int DIM=2;
struct matrix{
	ll a[11][11];
};
matrix operator*(matrix A, matrix B) {
    matrix C;
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)  {
            C.a[i][j] = 0;
            for(int t=0;t<DIM;t++)
                C.a[i][j] = (C.a[i][j] + (A.a[i][t] * B.a[t][j])%MOD) %MOD;
        }
    return C;
}
matrix pow_matrix(matrix a, int n) {
    if (n == 1) return a;
    matrix b = pow_matrix(a, n / 2);
    if (n & 1) return b * b * a;
    return b*b;
}
int main(){
	int t;
	cin >> t;
    int k;
	while(t--){
		cin >> k;
		matrix x, y;
        //1 1
        //1 0
        x.a[0][0]=1;
        x.a[0][1]=1;
        x.a[1][0]=1;
        x.a[1][1]=0;
        y=pow_matrix(x,k);
        cout<<y.a[0][1]<<endl;
    }	
	return 0;
}