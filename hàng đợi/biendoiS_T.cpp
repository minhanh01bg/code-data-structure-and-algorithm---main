#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define Begin() int N; cin>>N; cin.ignore(); while(N--)

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pause() system("pause");
 
// Namespaces

using namespace std;
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
unordered_map<ll,ll> mymap, CTCW;
 
ll a,b;
 
ll answer;

void Process()
{
	mymap.clear();
	queue<ll> C;
	C.push(a);
	mymap[a] = 0;
	ll steps = 0;
	while(!C.empty())
	{

		ll x = C.front();
		steps = mymap[x];
		C.pop();
		if(!mymap[x * 2])
		{
			mymap[x * 2] = steps + 1;
			C.push(x * 2);
		}
		if(!mymap[x - 1]) 
		{
			mymap[x - 1] = steps + 1;
			C.push(x - 1);
		}
		if (mymap[C.back()] >= 15) return;
	}
}
 
void Go()
{
	CTCW.clear();
	queue<ll> C;
	C.push(b);
	ll steps = 0;
	CTCW[b] = 0;
	while(!C.empty())
	{
		ll x = C.front();
		C.pop();
		steps = CTCW[x];
		if (mymap[x])
		{
			answer = mymap[x] + CTCW[x];
			return;
		}
		if(!CTCW[x + 1])
		{
			CTCW[x + 1] = steps + 1;
			C.push(x + 1);
		}
		if (x % 2 == 0 && !CTCW[x / 2])
		{
			CTCW[x / 2] = steps + 1;
			C.push(x / 2);
		}
	}
}
 
int main()
{
	faster();
	Begin()	{
		cin>>a>>b;
		answer = -1;
		Process();
		Go();
		cout<<answer<<endl;
	}
}