#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN int t;cin>>t;while(t--)
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
using namespace std;
 
void nextGreater(int arr[], int n, int next[], char order)
{
    stack<int> S;
    for (int i=n-1; i>=0; i--)
    {
        while (!S.empty() && ((order=='G')? arr[S.top()] <= arr[i]:arr[S.top()] >= arr[i]))
            S.pop();
        if (!S.empty())
            next[i] = S.top();
 
        else
            next[i] = -1;
 
        S.push(i);
    }
}
 
void nextSmallerOfNextGreater(int arr[], int n)
{
    int NG[n]; 
    int RS[n]; 
 
    nextGreater(arr, n, NG, 'G');

    nextGreater(arr, n, RS, 'S');
    FOR(i, 0, n)
    {
        if (NG[i] != -1 && RS[NG[i]] != -1)
            cout << arr[RS[NG[i]]] << " ";
        else
            cout<<"-1"<<" ";
    }
}

int main()
{
    FAST
    BEGIN{
        int n;
        cin>>n;
        int arr[n];
        FOR(i,0,n) 
            cin>>arr[i];
        nextSmallerOfNextGreater(arr, n);
        cout<<"\n";
    }
    return 0;
}