#include<bits/stdc++.h>
using namespace std;
long long minCost(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);

    long long res = 0;
 
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    return res;
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