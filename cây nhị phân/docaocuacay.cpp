#include<bits/stdc++.h>
    #define ll long long
// test

    #define BEGIN() int t;cin>>t;while(t--)
    #define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
	
// acronym
    #define pob pop_back
    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)
    
    using namespace std;
    
int main(){
    FAST()
    BEGIN(){
        int n;
        cin>>n;
        int arr[100000+1];
        int x,y;
        FOR(i,1,100000+1) arr[i]=0;
        FOR(i,1,n-1) {
            cin >> x >> y;
            arr[y]=arr[x]+1;
        }
        cout<<*max_element(arr,arr+100000+1);
        cout<<endl;
    }           
}
