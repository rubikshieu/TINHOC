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
    int test;
    cin >> test;
    while(test--){
        int n, k, gap;
        cin >> n >> k >> gap;
        int res = (k) * (k - 1) / 2;
        n -= k;
        if (n < 0){
            res = -1;
        }
        else{
            if (k == gap){
                res += (k - 1) * n;
            }
            else if (k > gap + 1){
                res = -1;
            }
            else{
                res += n * gap;
            }
        }
        cout << res << endl;

    }
    return 0;
}