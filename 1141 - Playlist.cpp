/***    Bismillahir Rahmanir Rahim    ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ll          long long
#define     ss          second
#define     ff          first
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn
#define     mem(a, x)   memset(a , x ,sizeof a)
#define     pi          3.1415926536
#define     deg(n)      n*PI/180
#define     sp(n,d)     fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());

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

       int i = 1, j = 1;
       int ans = -1, len = 0;
       map<int, int>freq;

       while(i <= n){
        if(freq.find(a[i]) == freq.end() or freq[a[i]] == 0){
            len++;
            freq[a[i]]++;
            ans = max(ans, len);
            i++;
        }
        else{
            len--;
            freq[a[j]]--;
            j++;
        }
       }
       cout << ans << nn;
    }
    return 0;
}
