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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        unordered_map <int,int> s;
        for (int j = 1; j < i; j++){
            int k = a[i] - a[j];
            if (s[a[j] - k] == 0){
                ans++;
            }
            s[a[j]] = 1;
        }
    }

    cout << ans;

    return 0;
}