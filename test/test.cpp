#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int n = 2; n <= 100; n++){
        int res = 0;
        for (int i = 1; i < n; i++){
            res += (n - i) * (n - i);
        }
        cout << n << ": " << 5 * n * n - res << endl;
    }
    return 0;
}