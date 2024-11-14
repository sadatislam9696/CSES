#include<bits/stdc++.h>
using namespace std;

#define nn '\n'
const int N = 1e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;


int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
pair<int, int> pref[N];
void build(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
}
pair<int, int> get_hash(int i, int j) {
  assert(i <= j);
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;
  hs.second = pref[j].second;
  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;
  return hs;
}

string s; 
pair<pair<int, int>, bool> ok(int l){

   map<pair<int, int>, int>cnt;
   for(int i = 0; i + l - 1 < s.size(); i++){
     pair<int, int>p = get_hash(i, i + l - 1);
     cnt[p]++;
   }

   for(auto it : cnt){
     if(it.second > 1){
        pair<pair<int, int>, bool>p;
        p.first.first = it.first.first;
        p.first.second = it.first.second;
        p.second = 1;
        return p;
     }
   }
   pair<pair<int, int>, bool>p;
   p.first.first = 0;
   p.first.second = 0;
   p.second = 0;
   return p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();
  cin >> s; 
  build(s);


  pair<pair<int, int>, int>ans;
  int n = s.size(); 
  int l = 1, r = n;

  while(l <= r){
    int mid = (l + r) >> 1; 
    //cout << mid << nn;
    pair<pair<int, int>, bool>p = ok(mid); 
    if(p.second){
      ans.first.first = p.first.first;
      ans.first.second = p.first.second;
      ans.second = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }

  pair<int, int>x; 
  x.first = ans.first.first;
  x.second = ans.first.second;

  int len = ans.second, flag = 0;;
  for(int i = 0; i + len - 1 < s.size(); i++){

    if(x == get_hash(i, i + len - 1)){
      cout << s.substr(i, len) << endl;
      flag = 1;
      break; 
    }
  }
  if(!flag){
     cout << -1 << endl;
  }
}
