#include<bits/stdc++.h>
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
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define begin() int t;cin>>t;while(t--)
using namespace std;
string decode(string str);
int main(){
	fast()
	begin(){
		string s;
		cin>>s;
		cout<<decode(s)<<endl;
		
	}
}
string decode(string str)
{
    stack<int> integerstack;
    stack<char> stringstack;
    string temp = "", result = "";
    FOR(i,0,str.size()) {
        int count = 0;
        if (str[i] >= '0' && str[i] <='9') {
            while (str[i] >= '0' && str[i] <= '9') {
                count = count * 10 + str[i] - '0';
                i++;
            }
  
            i--;
            integerstack.push(count);
        }
        else if (str[i] == ']') {
            temp = "";
            count = 0;
  
            if (! integerstack.empty())
            {
                count = integerstack.top();
                integerstack.pop();
            }
  
            while (! stringstack.empty() && stringstack.top()!='[' )
            {
                temp = stringstack.top() + temp;
                stringstack.pop();
            }
  
            if (! stringstack.empty() && stringstack.top() == '[')
                stringstack.pop();
            for (int j = 0; j < count; j++)
                result = result + temp;

            for (int j = 0; j < result.length(); j++)
                stringstack.push(result[j]);
  
            result = "";
        }
        else if (str[i] == '[') {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                stringstack.push(str[i]);
  
            else {
                stringstack.push(str[i]);
                integerstack.push(1);
            }
        }
        else
            stringstack.push(str[i]);
    }
    while (! stringstack.empty()) {
        result = stringstack.top() + result;
        stringstack.pop();
    }
    return result;
}