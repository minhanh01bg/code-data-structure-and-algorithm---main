#include<bits/stdc++.h>

using namespace std;
// code by vu minh anh
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for (int i=l;i>=r;i--)
#define BEGIN() int t;cin>>t;while(t--)
#define FAST() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define endl "\n"
#define RESET(C) memset(C,0,sizeof(C))
const ll mod=1e9+7;
//
int pro_data(int array[], int n){
    sort(array, array + n);
    int i = n / 2,j = n - 1;
    int ans = n;
    while(i >= 0 && j >= n / 2){
        if(array[i]*2 <= array[j]){
            ans--; i--; j--;
        }
        else i--;
    }
    return ans;
}
int main(){
    FAST()
    BEGIN(){
        int n;
        cin >> n;
        int array[n];
        FOR(i, 0, n - 1)
            cin >> array[i];
        cout<< pro_data(array, n) << "\n";
    }
}