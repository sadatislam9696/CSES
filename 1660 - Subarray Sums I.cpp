#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, x;
    cin >> n >> x;

    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;
    ll sum = 0, l = 1;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum > x){
            while(l < i and sum > x){
                sum -= a[l];
                l++;
            }

            if(sum == x){
                ans++;
            }
        }
        else{
            if(sum == x){
                ans++;
            }
        }
    }
    //cout << l << endl;
    cout << ans << '\n';
}
