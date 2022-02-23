#include<bits/stdc++.h>
using namespace std;
int p=1e9+7;
typedef long long ll;
long long minCost(int arr[], int n){
    priority_queue<ll, vector<ll>, greater<ll> > pq(arr, arr + n);

    long long res = 0;
 
    while (pq.size() > 1) {
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        res += (first + second)%p;
        pq.push((first + second)%p);
    }
    return res%p;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<minCost(a,n)<<endl;
    }
}