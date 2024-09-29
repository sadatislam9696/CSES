/**   Bismillahir Rahmanir Rahim    **/
 
#include<bits/stdc++.h>
using   namespace  std;
 
#define    nn      '\n'
#define    ll long long
 
bool cmp(pair<int, int>x, pair<int, int>y)
{
     return x.second < y.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
 
       int a[n + 1];
       for(int i = 1; i <= n; i++)
       {
           cin >> a[i];
       }
 
       multiset<int>tower;
 
       for(int i = 1; i <= n; i++)
       {
           auto it = tower.upper_bound(a[i]);
 
           if(it != tower.end())
           {
               tower.erase(it);
               tower.insert(a[i]);
           }
           else tower.insert(a[i]);
       }
 
       cout << tower.size() << nn;
    }
 
    return 0;
}
