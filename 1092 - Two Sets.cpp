/***    Bismillahir Rahmanir Rahim    ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ll          long long
#define     ld          long double
#define     ss          second
#define     ff          first
#define     yes         cout << "Yes" << nn
#define     no          cout << "No" << nn
#define     A           cout << "Alice" << nn
#define     B           cout << "Bob" << nn
#define     pi          3.1415926536
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a , x ,sizeof a)

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 +  7;
const int N = 2e5 + 9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
      int n;
      cin >> n;

      ll x = (1LL * n * (n + 1)) / 2;

      if(x % 2 == 1){
        cout << "NO" << nn;
        continue;
      }

      x = x / 2;
      ll sum = 0;
      vector<int>v1, v2;
      for(int i = n; i >= 1; i--){
        if((sum + i) <= x){
            sum += i;
            v1.push_back(i);
        }
      }
      reverse(v1.begin(), v1.end());
      int j = 0;

      for(int i = 1; i <= n; i++){
        if(i != v1[j]) v2.push_back(i);
        else j++;
      }

      cout  << "YES" << nn;
      cout << v1.size() << nn;
      for(auto it : v1){
        cout << it << ' ';
      }
      cout << nn;
      cout << v2.size() << nn;
      for(auto it : v2){
        cout << it << ' ';
      }
    }
    return 0;
}
