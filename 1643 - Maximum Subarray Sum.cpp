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

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        ll mx = -1e18, ans = -1e18;
        for(int i = 1; i <= n; i++){
            mx = max<ll>(a[i], mx + a[i]);
            ans = max<ll>(mx, ans);
        }
        cout << ans << nn;
    }
    return 0;
}
