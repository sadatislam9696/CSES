/***    Bismillahir Rahmanir Rahim    ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ll          long long
#define     ld          long double
#define     ss          second
#define     ff          first
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn
#define     pi          3.1415926536
#define     deg(n)      n*PI/180
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a , x ,sizeof a)

typedef     pair<int,int>   pii;
typedef     pair<ll,ll>     pll;
typedef     vector<int>     vi;
typedef     vector<ll>      vl;
typedef     vector<pii>     vii;
typedef     vector<pll>     vll;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};
const int M = 1e9 + 7;

void print(multiset<int>s){
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it  << ' ';
    }
    cout << nn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        multiset<int>s;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            s.insert(x);
        }
        while(m--){
            int x;
            cin >> x;
            //print(s);
            auto it = s.lower_bound(x);
            //cout << "x : " << x << " : " << (*it) << nn;

            if((it == s.begin() and x < *(s.begin())) or s.empty()){
                cout << -1 << ' ';
                continue;
            }
            if((!s.empty() and it == s.end())){
                --it;
                cout << *(it) << ' ';
                s.erase(s.find((*it)));
                continue;
            }

            if(x < (*it)){
              --it;
              cout << *it << ' ';
              s.erase(s.find(*(it)));
            }
            else{
             cout << *it << ' ';
             s.erase(s.find(*it));
             }
        }
        //print(s);
    }
    return 0;
}
