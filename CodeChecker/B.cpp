#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1 << 20 + 1;

int a[maxN];
bitset <maxN> dp[21][21];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    // freopen("HAMMING.INP", "r", stdin);
    // freopen("HAMMING.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[0][0][a[i]] = 1;
        // cout << bitset<4>(a[i]) << endl;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 0; j <= i; j++){
            for (int mask = 0; mask < (1 << m); mask++){
                dp[i][j][mask] = dp[i - 1][j][mask];
                if (dp[i][j][mask] == 0){
                    dp[i][j][mask] = dp[i - 1][j - 1][mask xor (1 << (i - 1))];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        int res = 0;
        for (int cnt = 1; cnt <= m; cnt++){
            if (dp[m][cnt][a[i]]){
                res = cnt;
            }
        }
        cout << res << " ";
    }

    return 0;
}

/*
1001
1001
1011
1100
*/