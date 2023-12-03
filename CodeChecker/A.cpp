#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN];
int dp[maxN][maxN];
int nxtl[maxN];
int nxtr[maxN];

int cal(int l, int r){
    if (dp[l][r] != 0){
        return dp[l][r];
    }
    if (l > r){
        return 0;
    }
    if (l == r){
        return dp[l][r] = 1;
    }
    int &res = dp[l][r] = min(cal(l + 1, r), cal(l, r - 1)) + 1;
    // cout << l << " " << r << ": " << res << endl;
    for (int mid = l; mid <= r; mid++){
        if (a[l] == a[mid]){
            int tres = cal(l + 1, mid - 1) + 1 + cal(mid + 1, r) - (a[l] == a[r] and mid != r);
            // cout << l << " " << mid << ' ' << r << ": " << tres << endl;
            res = min(res, tres); 
        }
    }
    // cout << l << ' ' << r << ": " << res << endl;
    return res;
}

/*
1234567
010212
3031323
*/

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DELSTR.inp", "r")) {
        freopen("DELSTR.inp", "r", stdin);
        freopen("DELSTR.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 1;
    a[0] = a[n + 1] = -1;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[cnt] = c - 'a';
        if (a[cnt - 1] != a[cnt]){
            cnt++;
        }
    }
    n = cnt - 1;
    // for (int i = 1; i <= n; i++){
    //     cout << a[i];
    // }
    // cout << endl;
    cout << cal(1,n) << endl;
    return 0;
}

/*
1234567890
abaaaccbcc
*/