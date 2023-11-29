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
    int n, k;
    cin >> n >> k;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int m;
        cin >> m;
        int t;
        cin >> t;
        int s;
        cin >> s;
        ls.push_back({abs(s),t});
    }
    ls.push_back({0,0});
    sort(all(ls));
    int res = 0;
    for (int i = 1; i <= n; i++){
        int t = ls[i].se;
        res = max(res, ls[i].fi - ls[i - 1].fi);
        for (int j = i, cnt = 0; j <= n; j++){
            if (ls[j].se != t){
                cnt++;
            }
            if (cnt > k){
                break;
            }
            res = max(res, ls[j].fi - ls[i - 1].fi);
            cout << i << " " << j << " " << ls[j].fi << " " << ls[i - 1].fi << " " << res << endl;
        }
    }
    cout << res << endl;
    cout << res / 2 << ".";
    if (res % 2){
        cout << 5;
    }
    else{
        cout << 0;
    }
    return 0;
}