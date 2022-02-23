#include<bits/stdc++.h>

using namespace std;
typedef long long ll;  

long long u =1e9 +7, k; int n;
int MOD=1e9+7;
int DIM;
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
		cin >> DIM >> k;
		matrix x, y;

        for(int i=0;i<DIM;i++){
            for(int j=0;j<DIM;j++){
                cin>>x.a[i][j];
            }
        }
        y=pow_matrix(x,k);

        for(int i=0;i<DIM;i++){
            for(int j=0;j<DIM;j++){
                cout<<y.a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }	
	return 0;
}