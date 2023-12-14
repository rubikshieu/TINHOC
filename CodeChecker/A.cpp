#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool cmp(ii a, ii b){
    return a.fi * b.se < b.fi * a.se;
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
    vector <ii> ls;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }

    sort(all(ls), cmp);
    ii res = {0,0};
    while(k--){
        res.fi += ls.back().fi;
        res.se += ls.back().se;
        cout << ls.back().fi << " " << ls.back().se << endl;
        ls.pop_back();
    }

    int g = __gcd(res.fi, res.se);

    res.fi /= g;
    res.se /= g;

    cout << res.fi << " " << res.se << endl;
    return 0;
}