#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int mod = 998244353;
const int maxN = 1e7 + 10;
int fact[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
}
int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}


int C(int n, int k){
    if (n < k){
        return 0;
    }
   return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    set <char> s;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        if (x == '?'){
            cnt++;
            continue;
        }
        s.insert(x);
    }

    cout << s.size() << " " << cnt << endl;

    if (s.size() + cnt != n){
        cout << 0;
    }
    else if (cnt == 0){
        cout << 1 << endl;
    }
    else{
        cout << C(26 - s.size(), cnt);
    }
    return 0;
}
