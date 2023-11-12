#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 100 + 10;
const int mod = 1e9 + 7;

int fact[maxN];
int infact[maxN];
int cnt[maxN];

int add(int a, int b, int MOD = mod){
    return (a + b) % MOD;
}
int subtr(int a, int b, int MOD = mod){
    return ((a + MOD) - b) % MOD; 
}
int mul(int a, int b, int MOD = mod){
    return (a * b) % MOD;
}
int fastpow(int n, int a, int MOD = mod){
    if (a == 1){
        return n;
    }
    if (a == 0){
        return 1;
    }
    int temp = fastpow(n, a / 2, MOD);
    int ans = mul(temp, temp, MOD);
    if (a % 2){
        return mul(ans, n, MOD);
    }
    else{
        return ans;
    }
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = fastpow(fact[maxN - 1], mod - 2);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], i + 1);
    }
    
}
int C(int n, int k){
    return mul(fact[n], mul(infact[k], infact[n - k]));
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    int MA = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 1; j * j <= x; j++){
            if (x % j == 0){
                cnt[j]++;
                // cout << j << endl;
                if (x / j != j){
                // cout << x / j << endl;
                    cnt[x / j]++;
                }
            }
        }
        MA = max(MA, x);
    }

    int res = 1;
    // for (int i = 1; i <= MA; i++){
    //     cout << i << " " << cnt[i] << endl;
    // }
    for (int i = 2; i <= MA; i++){
        if (cnt[i]){
            // cout << "With: " << i << endl;
            int num = 1;
            int temp = cnt[i];
            int la = i;
            for (int j = i + i; j <= MA; j += i){
                if (cnt[j]){
                    if (temp - cnt[j] <= 0){
                        if (la == i){
                            goto bru;
                        }
                        continue;
                    }
                    temp -= cnt[j]; 
                    // cout << la << " " << temp << endl; 
                    num = mul(num, fastpow(2,temp, mod - 1), mod - 1);
                    // cout << "()" << la << " " << i << endl;
                    if (la == i){
                        // cout << num << endl;
                        num = subtr(num, 1, mod - 1);
                    }
                    temp = cnt[j];
                    la = j;
                }
            }
            // cout << la << " " << temp << endl; 
            num = mul(num, fastpow(2,temp, mod - 1), mod - 1);
            if (la == i){
                    num = subtr(num, 1, mod - 1);
            }
            // cout << num << endl;
            res = mul(res, fastpow(i, num));
            bru:;
        }
    }

    cout << res << endl;
    return 0;
}

/*
2 4 6
3 2 1
1 1 1

a^b = a^(b % (mod - 1))
*/